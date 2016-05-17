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
END_MESSAGE_MAP()


int CFlowControl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}
