#include "StdAfx.h"
#include "FlowListCtrl.h"


BEGIN_MESSAGE_MAP(CFlowListCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CFlowListCtrl::OnNMCustomdraw)
END_MESSAGE_MAP()

CFlowListCtrl::CFlowListCtrl(void)
{
}


CFlowListCtrl::~CFlowListCtrl(void)
{
}


void CFlowListCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = CDRF_DODEFAULT;
	NMLVCUSTOMDRAW * lplvdr=(NMLVCUSTOMDRAW*)pNMHDR;
	NMCUSTOMDRAW &nmcd = lplvdr->nmcd;
	switch(lplvdr->nmcd.dwDrawStage)//�ж�״̬
	{
	case CDDS_PREPAINT:
		{
			*pResult = CDRF_NOTIFYITEMDRAW;
			break;
		}
	case CDDS_ITEMPREPAINT://���Ϊ��ITEM֮ǰ��Ҫ������ɫ�ĸı�
		{
			lplvdr->clrTextBk = RGB(255, 0, 0);
			*pResult = CDRF_DODEFAULT;
		}
		break;
	}
}