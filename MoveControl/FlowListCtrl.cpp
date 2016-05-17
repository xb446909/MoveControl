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
	switch(lplvdr->nmcd.dwDrawStage)//判断状态
	{
	case CDDS_PREPAINT:
		{
			*pResult = CDRF_NOTIFYITEMDRAW;
			break;
		}
	case CDDS_ITEMPREPAINT://如果为画ITEM之前就要进行颜色的改变
		{	
			*pResult = CDRF_DODEFAULT;
		}
		break;
	}
}


void CFlowListCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	TCHAR lpBuffer[256];
	LV_COLUMN lvc;
	::ZeroMemory(&lvc, sizeof(lvc));
	lvc.mask = LVCF_WIDTH | LVCF_FMT;
	long hight = 0;
	for (int nCol = 0; GetColumn(nCol, &lvc); nCol++)
	{
		lpDrawItemStruct->rcItem.left += hight;
		lpDrawItemStruct->rcItem.right += hight;
		hight = lvc.cx;
		LV_ITEM lvi;
		::ZeroMemory(&lvi, sizeof(lvi));
		lvi.iItem = lpDrawItemStruct->itemID;
		lvi.mask = LVIF_TEXT | LVIF_PARAM;
		lvi.iSubItem = nCol;
		lvi.pszText = lpBuffer;
		lvi.cchTextMax = sizeof(lpBuffer);
		VERIFY(GetItem(&lvi));
		CDC* pDC;
		pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
		if (lpDrawItemStruct->itemState & ODS_SELECTED)
		{
			pDC->FillSolidRect(&lpDrawItemStruct->rcItem, RGB(231, 243, 229));
			pDC->SetTextColor(RGB(255, 0, 0));
		}
		else
		{
			pDC->FillSolidRect(&lpDrawItemStruct->rcItem, GetSysColor(COLOR_WINDOW));
			pDC->SetTextColor(GetSysColor(COLOR_WINDOWTEXT));
		}
		if (lvi.iItem == 0)
		{
			pDC->FillSolidRect(&lpDrawItemStruct->rcItem, RGB(255, 0, 0));
		}
		//CFont lfont;
		//lfont.CreateFont(14, 0, 0, 0, FW_BOLD ,0, 1, 0, GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH ,"Consolas");
		//CFont* pold = pDC->SelectObject(&lfont);
		::DrawText(lpDrawItemStruct->hDC, lpBuffer, wcslen(lpBuffer), &lpDrawItemStruct->rcItem, DT_LEFT);
		//pDC->SelectStockObject(SYSTEM_FONT) ;
		m_imgList.Draw(pDC, 0, CPoint(0, 24), ILD_TRANSPARENT);
	}
}
