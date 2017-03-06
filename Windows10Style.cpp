#include "stdafx.h"
#include "Windows10Style.h"

using namespace Gdiplus;

IMPLEMENT_DYNCREATE(CWindows10Style, CMFCVisualManagerOffice2007);

CWindows10Style::CWindows10Style()
{
    m_crlBkgn = RGB(0xFF, 30, 30);

    CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);

    m_tabFaceBrush.CreateSolidBrush(GetSysColor(COLOR_HOTLIGHT));
    m_tabBlackBrush.CreateSolidBrush(GetSysColor(COLOR_WINDOWFRAME));
}

CWindows10Style::~CWindows10Style()
{ }

