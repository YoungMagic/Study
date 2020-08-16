## Django+celery+redis_or_rabbitMQ配置
- 运行环境：
```
操作系统：WIN10
Django: 3.0.3
celery: 3.1.26
redis: 3.0
rabbitMQ: 3.8.2
```

#### 何为任务队列？
任务队列是一种在线程或机器间分发任务的机制。 

消息队列的输入是工作的一个单元，称为任务，独立的职程（Worker）进程持续监视队列中是否有需要处理的新任务。 

Celery 用消息通信，通常使用中间人（Broker）在客户端和职程间斡旋。这个过程从客户端向队列添加消息开始，之后中间人把消息派送给职程。 

Celery 系统可包含多个职程和中间人，以此获得高可用性和横向扩展能力。 

Celery 需要一个发送和接受消息的传输者。RabbitMQ 和 Redis 中间人的消息传输支持所有特性，但也提供大量其他实验性方案的支持，包括用 SQLite 进行本地开发。 
- 安装：
pip install -U Celery
pip install -U django-celery
![各部分关系](https://i.imgur.com/tcg7Adx.png)

### 新建Django项目进行测试
1. 新建项目
```
python manage.py startproject super
cd super
python manage.py startapp calc_md5
```
2. 修改settings.py, 加入
```
import os
import djcelery

djcelery.setup_loader()

CELERY_TIMEZONE = 'Asia/Shanghai'
TIME_ZONE = 'Asia/Shanghai'

BROKER_URL = 'amqp://guest@localhost//' # 使用rabbitMQ作为中间人或者使用redis:BROKER_URL = 'redis://localhost:6379/0'
# CELERY_RESULT_BACKEND = 'amqp://guest@localhost//' #用于存储任务的执行结果，请勿使用MQ，使用MQ会把每一个结果作为一条信息存储，最终内存溢出https://docs.celeryproject.org/en/stable/faq.html
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'lists',
    'calc_md5', #加入新创建的应用
    'djcelery', #加入djcelery
]
```
3. 在super应用下新建celery.py并填入
```
#!/bin/python
from __future__ import absolute_import
 
import os
 
from celery import Celery
 
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'djtest1.settings')
#Specifying the settings here means the celery command line program will know where your Django project is. 
#This statement must always appear before the app instance is created, which is what we do next: 
from django.conf import settings
 
app = Celery('djtest1')
 
app.config_from_object('django.conf:settings')
#This means that you don’t have to use multiple configuration files, and instead configure Celery directly from the Django settings.
#You can pass the object directly here, but using a string is better since then the worker doesn’t have to serialize the object.
 
app.autodiscover_tasks(lambda: settings.INSTALLED_APPS)
#With the line above Celery will automatically discover tasks in reusable apps if you define all tasks in a separate tasks.py module.
#The tasks.py should be in dir which is added to INSTALLED_APP in settings.py. 
#So you do not have to manually add the individual modules to the CELERY_IMPORT in settings.py.
 
@app.task(bind=True)
def debug_task(self):
    print('Request: {0!r}'.format(self.request))  #dumps its own request information
```
4. 修改super应用下的init.py
```
#!/bin/python
from __future__ import absolute_import
 
# This will make sure the app is always imported when
# Django starts so that shared_task will use this app.
from .celery import app as celery_app
```
5. 在cala_md5应用下新建tasks.py
```
from __future__ import absolute_import
 
from celery import task
 
from celery import shared_task
 
#from celery.task import tasks 
#from celery.task import Task 
 
@task()
#@shared_task
def add(x, y):
    print "%d + %d = %d"%(x,y,x+y)
    return x+y
#class AddClass(Task):
#    def run(x,y):
#        print "%d + %d = %d"%(x,y,x+y)
#        return x+y
#tasks.register(AddClass)
 
@shared_task
def mul(x, y):
    print "%d * %d = %d"%(x,y,x*y)
    return x*y
 
@shared_task
def sub(x, y):
    print "%d - %d = %d"%(x,y,x-y)
    return x-y
```
6. 数据库操作
```
python manage.py makemigrations
 
python manage.py migrate
```
7. 启动celery worker进行消费
```
python manage.py  celery worker -c 6 -l debug  #任务执行进程，worker进程
```
8. 测试
```
python manage.py shell
from calc_md5.tasks import add
while True:
    import time
    add.delay(2,5)
    time.sleep(3)
```
9. 结果
celery执行结果
![avatar](https://github.com/YoungMagic/Study/blob/master/media/celery.png)

10. 启动多worker
在装饰器上可以指定任务类型以及走的队列，比如 *@task(base=BaseTask, queue='red')*，该任务走名为red的队列。
BaseTask重写celery.app.base.Celery.task的参数，可以设置最大重复次数等

启动名为red，队列为red的worker。*python manage.py celery worker -c 6 -l debug -n red -Q red*

- 参考： 

https://blog.csdn.net/bbwangj/article/details/89312355 

http://docs.jinkan.org/docs/celery/ 

http://blog.hellsec.net/coding/2019/10/08/celery-timeout-tips/ celery timeout机制 
https://docs.celeryproject.org/en/3.1/configuration.html#std:setting-CELERYD_TASK_TIME_LIMIT 文档 
