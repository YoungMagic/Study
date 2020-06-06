## 目前使用的图像压缩方法
目前推荐使用的是行外的TinyPNG及行内搭建的Squoosh
### TinyPNG
TinyPNG使用智能有损压缩技术将PNG及JPEG文件的文件大小降低。通过选择性的减少图片中的颜色，只需要较少的字节数就能保存数据。
#### 特点
- 无需额外设置参数，即传即压缩。
- 可批量处理图像
#### 存在的问题
- 免费用户单次最多只能压缩20张图片，每张图片最大只有5MB
### Squoosh
Squoosh是Google开源发布的一款专门用来压缩图片的在线服务，支持 JPG、PNG、WebP 等格式的压缩。
#### 特点
- 具有可视化压缩界面，可调整图像尺寸、格式、质量，自定义程度高
#### 存在的问题
- 功能强大，但上手门槛比TinyPNG高
- 一次只能处理一张图片
## 目的
为了提供给用户更完整及一体化的体验，在平台内上传图像素材时，能够实现图像自动压缩，无需额外使用TinyPNG、Squoosh等工具用来压缩图像。
## 图像压缩库
- PIL:PIL（Python Imaging Library）是Python图像处理库，该库支持多种文件格式，提供强大的图像处理功能
- OptiPNG:OptiPNG是一个PNG优化库，可以将图像文件压缩为较小的文件，而不会丢失任何信息。该程序还将其他格式（BMP，GIF，PNM和TIFF）转换为优化的PNG。
- pngquant:pngquant是一个用于PNG图片有损压缩的库。转换会大大减少文件大小（通常多达70％），并保留图像文件的透明度。
### 测试对比
用PIL处理jpeg格式图像，OptiPNG和pngquant分别处理png图像。结果如下：


## 素材管理改造方案
使用PIL库处理jpeg格式图像，pngquant处理png图像，其他格式暂不处理（其它格式数量少）
### 处理流程
flow
st=>start:用户上传图片
op1=>operation:获取该图片，upload_file=request.FILES.get('file', None)
op2=>operation:PIL读取该图片并判断格式，im=Image.open(upload_file)
cond=>condition:jpg or png or else
op3=>operation:直接压缩
op4=>operation:为该用户在tmp文件夹生成一个临时文件夹，保存该图片在文件夹内
op5=>operation:压缩
op6=>operation:返回该文件
op7=>operation:执行接下来的上传等步骤
cond(jpg)->op3
cond(png)->op4
cond(else)->op7