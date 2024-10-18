
// MFCApplication1View.cpp: CMFCApplication1View 类的实现
//






#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFCApplication1View::On32771)
	ON_COMMAND(ID_32772, &CMFCApplication1View::On32772)

	ON_COMMAND(ID_32774, &CMFCApplication1View::On32774)
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘图

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	


}


// CMFCApplication1View 打印

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序

//画出三角形代码，
void CMFCApplication1View::On32771()
{
	// TODO: 在此添加命令处理程序代码

	CClientDC dc(this);
	CPen pen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = dc.SelectObject(&pen);
	CPoint pt[3] = { CPoint(375,20),CPoint(490,200), CPoint(260,200) };
	dc.Polygon(pt, 3);
}

//画出矩形由外向内的动画代码

void CMFCApplication1View::On32772()
{
	// TODO: 在此添加命令处理程序代码

	
	
	CClientDC dc(this);
	CPen pen(PS_SOLID, 3, RGB(0, 128, 255));
	CPen* oldPen = dc.SelectObject(&pen);

	// 确定中心点坐标
	CPoint center(215, 375); // 正方形的中心位置

	// 调整循环次数，绘制更多的正方形
	int totalIterations = 15;  // 设置更多次循环

	// 控制步长，使正方形更加密集
	int stepSize = 10;  // 每次缩小的步长较小，产生更多的嵌套正方形

	// 循环次数控制正方形数量
	for (int i = 0; i < totalIterations; i++) {
		// 定义每次缩小的幅度
		int offset = i * stepSize;  // 控制正方形的缩小步长

		// 定义正方形的边长，最初的边长为 370（根据坐标(30, 400)计算）
		int sideLength = 370 - 2 * offset;  // 每次正方形缩小

		// 检查边长是否为正，确保不绘制过小的正方形
		if (sideLength <= 0) break;

		// 计算正方形的顶点位置，保持中心对称
		CPoint pt[4] = {
			CPoint(center.x - sideLength / 2, center.y - sideLength / 2),  // 左上角
			CPoint(center.x + sideLength / 2, center.y - sideLength / 2),  // 右上角
			CPoint(center.x + sideLength / 2, center.y + sideLength / 2),  // 右下角
			CPoint(center.x - sideLength / 2, center.y + sideLength / 2)   // 左下角
		};

		// 绘制正方形
		dc.Polygon(pt, 4);

		// 暂停一秒，模拟动画效果
		Sleep(500);  // 缩短暂停时间，动画更流畅
	}

	// 恢复原来的画笔
	dc.SelectObject(oldPen);

}


//画出小球的动画代码

void paintBall(int x, int y, int r, CDC* pDC)
{
	double angle, decrement;
	int colorValue;

	decrement = r / 255.0;  // 控制每次绘制的圆的半径递减量

	// 从外向内绘制小球，颜色从黑到白
	for (int w = r; w >= 0; w--) {
		colorValue = static_cast<int>(255 * (1.0 - (double)w / r)); // 计算当前颜色值，从 0 到 255 逐渐变化

		COLORREF color = RGB(colorValue, colorValue, colorValue); // 设置当前圆的颜色

		// 通过绘制每个像素点来画圆
		for (angle = 0; angle < 2 * 3.14159265358979323846; angle += 0.01) { // 角度变化控制圆周上的点
			int px = static_cast<int>(x + w * cos(angle));  // 圆上某一点的 x 坐标
			int py = static_cast<int>(y + w * sin(angle));  // 圆上某一点的 y 坐标

			pDC->SetPixel(px, py, color);  // 设置该点的颜色
		}
	}
}




void CMFCApplication1View::On32774()
{
	CDC* pDC = GetDC(); // 获取设备上下文
	paintBall(300, 300, 50, pDC); // 在 (300, 300) 绘制半径为 100 的小球，延迟为 20ms
	ReleaseDC(pDC); // 释放设备上下文

}
