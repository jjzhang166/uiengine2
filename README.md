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


/*
*class cSight
*视野，管理一个视野（即当前所能看到的所有事物）的内容
*/
class cSight:public cBaseUI,cMyTimer

```
### 使用示例
```
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   0,0,800,600, nullptr, nullptr, hInstance, nullptr);
   
   if (!hWnd)
   {
	   return FALSE;
   }
   MyEngine::cGameEngine::GetEngine()->init(hWnd);   //初始化并绑定窗口句柄
   MyEngine::cGameEngine::GetEngine()->CreateCircle(RECT{ 10,10,100,100 });   //新建一个圆
   MyEngine::cGameEngine::GetEngine()->CreateLine(POINT{ 20,30 }, POINT{ 100,200 });   //新建一个直线
   MyEngine::cButton* btn = new MyEngine::cButton(L"点我", 100, 30);   
   btn->SetX(100);
   btn->SetY(200);
   MyEngine::cGameEngine::GetEngine()->AddEngineUi(btn);    //出直接Create之外还可以，自己新建后添加到Engine。
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);


   //在程序结束的恰当位置必须调用MyEngine::cGameEngine::GetEmgine()->ReleaseSelf释放资源
```

### 示例效果图
![输入图片说明](https://git.oschina.net/uploads/images/2017/0819/151728_cf1f290e_1296205.jpeg "捕获.JPG")


### 2017/8/18:15:02第一次大更
添加资源池统一管理GDI句柄资源，主要是管理图片资源，资源池主要采用单例设计模式，一处加载到处使用。
添加CLock互斥锁，纠正了多线程下时常会发生的资源共享异常。这次更新同时也修复了以前经常会发生异常的bug

### 资源池使用实例
```
#include"cResourcePool.h"
class LoadResource
{
    public:
    LoadResource()
    {
       cResourcePool::AddObjByKey("pic1",(HBITMAP)LoadImage(nullptr,L"D:\\puc1.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE));
       cResourcePool::AddObjByKey("pic2",(HBITMAP)LoadImage(nullptr,L"D:\\puc2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE));
       cResourcePool::AddObjByKey("pic3",(HBITMAP)LoadImage(nullptr,L"D:\\puc3.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE));
       cResourcePool::AddObjByKey("pic4",(HBITMAP)LoadImage(nullptr,L"D:\\puc4.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE));
    }
   ~LoadResource(){};
    
}


#include"cResourcePool.h"
class Test
{
    public:
    Test()
    {
       HBITMAP h= cResourcePool::GethObjByKey("pic1");
    } 
    ~Test(){}   
}

上面的示例只是为了说明资源池中的资源，在加载之后可在任何地方使用，真实情况时用户而定，想要详细了解使用，可查看UIEngine源码，有详细注释

```

### 2017/8/19 15：26第二次更新

此次更新主要将cGameEngine类更改为单实例类，同时增加了一个cSight类用于辅助管理Engine的图形绘制。

### 2017/8/20 16：41第三次更新

此次更新主要重写了cMyTimer定时器类，修复了多线程下的资源共享问题；同时对cCircle圆类进行了一些细微的调整