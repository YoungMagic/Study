## 使用supervisor来管理进程
### 简介
Supervisor是用Python开发的一套通用的进程管理程序，能将一个普通的命令行进程变为后台daemon，并监控进程状态，异常退出时能自动重启。它是通过fork/exec的方式把这些被管理的进程当作supervisor的子进程来启动，这样只要在supervisor的配置文件中，把要管理的进程的可执行文件的路径写进去即可。也实现当子进程挂掉的时候，父进程可以准确获取子进程挂掉的信息的，可以选择是否自己启动和报警。supervisor还提供了一个功能，可以为supervisord或者每个子进程，设置一个非root的user，这个user就可以管理它对应的进程。

### 配置文件
配置文件在根目录下的autostart.conf文件中。启动的服务有编辑器，nginx，celery。此外，Supervisor可以控制被管理的进程的日志。
```
[program:xxx]
command=xxx
stdout_logfile= xxx 路径或者/dev/stdout，如果是/dev/stdout，且需设置stdout_logfile_maxbytes=0,就会把日志输出到终端.
autorestart=True
```

### 使用gunicorn来启动django
略

## 使用celery来处理异步任务
### 简介
Celery是一个简单、灵活且可靠的，处理大量消息的分布式系统

专注于实时处理的异步任务队列

同时也支持任务调度
#### 启动celery
项目中将Celery交给supervisor管理。
命令为*python manage.py celeryd -c 1 -f /xxx/xx.log -l INFO --pidfile /xxx/xxx/ -n xxx*
- -c:并发数
- -f:指定日志路径
- -l:日志等级
- -n:celery的名称，如果使用MQ，会在exchange中生成一个该名称的交换。
#### celery配置
详见上一篇文章
