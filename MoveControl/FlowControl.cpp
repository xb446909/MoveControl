#include "StdAfx.h"
#include "FlowControl.h"


CFlowControl* CFlowControl::pInst = new CFlowControl();

CFlowControl::CFlowControl(void)
{
}


CFlowControl::~CFlowControl(void)
{
}

CFlowControl* CFlowControl::Get()
{
	return pInst;
}
BEGIN_MESSAGE_MAP(CFlowControl, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


int CFlowControl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect rect;
	rect.SetRectEmpty();
	m_listCtrl.Create(WS_VISIBLE | WS_CHILD | LVS_REPORT | LVS_OWNERDRAWFIXED, rect, this, 1);
	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	m_listCtrl.m_imgList.Create(48, 48, ILC_COLOR32, 0, 5);
	m_listCtrl.SetImageList(&m_listCtrl.m_imgList, LVSIL_SMALL);
	CBitmap bmp;
	int result = bmp.LoadBitmap(IDB_BITMAP1);
	result = m_listCtrl.m_imgList.Add(&bmp, RGB(0, 0, 0));

	m_listCtrl.InsertColumn(0, L"序号", LVCFMT_LEFT, 100);
	m_listCtrl.InsertColumn(1, L"说明", LVCFMT_LEFT, 500);
	CString tmpStr;
	for (size_t i = 0; i < 20; i++)
	{
		tmpStr.Format(L"%d", i);
		m_listCtrl.InsertItem(i, tmpStr);
		m_listCtrl.SetItemText(i, 1, L"ITEM");
	}
	return 0;
}


void CFlowControl::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (m_listCtrl.GetSafeHwnd())
	{
		m_listCtrl.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
	}
}
