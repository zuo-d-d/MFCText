
// MFCTextView.cpp : CMFCTextView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCText.h"
#endif

#include "MFCTextDoc.h"
#include "MFCTextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTextView

IMPLEMENT_DYNCREATE(CMFCTextView, CView)

BEGIN_MESSAGE_MAP(CMFCTextView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCTextView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCTextView 构造/析构

CMFCTextView::CMFCTextView()
{
	// TODO: 在此处添加构造代码

}

CMFCTextView::~CMFCTextView()
{
}

BOOL CMFCTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCTextView 绘制

void CMFCTextView::OnDraw(CDC* /*pDC*/)
{
	CMFCTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCTextView 打印


void CMFCTextView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCTextView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCTextView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCTextView 诊断

#ifdef _DEBUG
void CMFCTextView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTextDoc* CMFCTextView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTextDoc)));
	return (CMFCTextDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTextView 消息处理程序
