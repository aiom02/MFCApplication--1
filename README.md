# MFCApplication1-河工大计算机图形学实验一

# **1.源码说明**

​      本仓库代码，是河南工业大学计算机图形学基础实验1的源代码。实现了画三角形，画矩形，和画真实小球的功能。

# **2.使用说明**

<img src="C:\Users\aiom\source\repos\计算机图形学基础实验\MFCApplication1\image-20241018150306709.png" alt="image-20241018150306709" style="zoom: 67%;" />

点击code 然后点击DownLoad ZIP，下载源码压缩包，解压后，点击MFCApplication1.sln即可。

<img src="C:\Users\aiom\source\repos\计算机图形学基础实验\MFCApplication1\image-20241018150507811.png" alt="image-20241018150507811" style="zoom:50%;" />

## 三、参考资料：

1.安装教程：

2.三角，矩形做法教程，**真手把手教学**：[使用Visual Studio进行MFC单文档下的菜单绘图（直线、三角形、正方形、逐渐向中心收缩的矩形）_vsmfc工具箱中的绘图框在哪-CSDN博客](https://blog.csdn.net/qq_42041632/article/details/133885607)

3.真实感小球，在参考2的基础上，结合老师学习通上的（第二单元讲义 绘图基础）的真实感部分，以及画小球的基本思路：

1.**外到内绘制同心圆**：从球的外层开始，每次缩小半径，逐步向球的内部绘制。

2.**颜色渐变**：每次绘制的圆颜色会根据半径变化，逐渐从黑色过渡到白色。

3.**绘制圆周上的点**：通过遍历每个角度，计算出圆周上的点坐标，并将其绘制出来。同一个圆周上的点，保持同一个颜色。



![image-20241018151125516](C:\Users\aiom\AppData\Roaming\Typora\typora-user-images\image-20241018151125516.png)

# 四、剩余疑问

  当我把小球半径从50改成100后，便会出现下面的图像。

![image-20241018151743118](C:\Users\aiom\source\repos\计算机图形学基础实验\MFCApplication1\image-20241018151743118.png)

/*

Author: aiom02

Date: October 18, 2024
*/



