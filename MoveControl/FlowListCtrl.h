#pragma once
#include "afxcmn.h"
class CFlowListCtrl :
	public CListCtrl
{
	DECLARE_MESSAGE_MAP()
public:
	CFlowListCtrl(void);
	~CFlowListCtrl(void);
private:
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
public:
	CImageList m_imgList;
};

