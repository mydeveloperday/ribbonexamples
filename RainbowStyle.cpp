#include "stdafx.h"
#include "RainbowStyle.h"
#include "resource.h"

using namespace Gdiplus;

IMPLEMENT_DYNCREATE(CRainbowStyle, CMFCVisualManagerOffice2007);

CRainbowStyle::CRainbowStyle()
{
    m_crlBkgn = RGB(0xFF, 30, 30);

    CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);

    m_tabFaceBrush.CreateSolidBrush(m_clrWindows10ApplicationButton);
    m_tabBlackBrush.CreateSolidBrush(GetSysColor(COLOR_WINDOWFRAME));

    // load the UI elements
    m_uiElements.Load(IDB_UI_ELEMENTS);
}

CRainbowStyle::~CRainbowStyle()
{ }

