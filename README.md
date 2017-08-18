C++编写的简单UI引擎，方便开发windows界面程序,附件中含有用此UI引擎开发的游戏地图编辑器和一个冒险小游戏（该游戏暂时还未做完）。
项目附件中有地图编辑器和冒险小游戏64位可执行文件。UiEngine文件夹中包含项目源码，UIEngneLib文件夹包含UI引擎静态链接库，可直接下载和UiEngine文件夹中的源码使用。
```
此UI引擎是对win32API的一个封装非常适合对win32API不熟悉但又需要使用win32API编程的开发使用。

class cGameEngine是引擎类其主要负责对UI界面的管理，通过这个类可以在界面上创建各种UI元素，并管理UI元素。
次说明书只是简单说明各个类的作用，详细说明及使用方法可查看项目源代码

/*
cBaseUI
所有UI类的基类
*/
class cBaseUI   

/*
cAmination
动画元素继承自cBaseUI
*/
class cAmination:public cBaseUI

/*
cButton
按钮元素继承自cBaseUI
*/
class cButton :public cBaseUI

/*
cCircle
圆元素继承自cBaseUI
*/
class cCircle:public cBaseUI

/*
cLine
直线元素继承自cBaseUI
*/
class cLine:public cBaseUI

/*
cMyTimer
定时器类
*/
class cMyTimer

/*
cPicture
图片元素继承自cBaseUI
*/
class cPicture:public cBaseUI

/*
Polygon
对边形元素继承自cBaseU
根据多边形基点循序依次连接形成多边形
*/
class cPolygon:public cBaseUI

/*
cRectangle
矩形元素继承自cBaseU
*/
class cRectangle:public cBaseUI

/*
cText
文本元素继承自cBaseU
*/
class cText:public cBaseUI

/*
cTriangle
三角形元素继承自cBaseU
*/
class cTriangle:public cBaseUI

/*
*class cResourcePool
*资源池，用于统一存放并管理GDI资源句柄，节省内存提升效率
*/
class cResourcePool

/*
*class CLock
*互斥锁
*/
class CLock

```

### 2017/8/18:15:02第一次大更
添加资源池统一管理GDI句柄资源，主要是管理图片资源。
添加CLock互斥锁，纠正了多线程下时常会发生的资源共享异常。

