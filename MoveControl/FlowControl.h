#pragma once
#include "afxdockablepane.h"
#include "FlowListCtrl.h"

class CFlowControl :
	public CDockablePane	
{
private:
	static CFlowControl* pInst;
public:
	CFlowControl(void);
	~CFlowControl(void);
	
	static CFlowControl* Get();
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	CFlowListCtrl m_listCtrl;
};

