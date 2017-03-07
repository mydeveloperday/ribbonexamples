#pragma once

class CWindows10Style : public CMFCVisualManagerOffice2007
{
    DECLARE_DYNCREATE(CWindows10Style);

private:
    CWindows10Style();

public:
    virtual ~CWindows10Style();

    // This is the color of a docking pane's caption
    virtual COLORREF OnDrawPaneCaption(
        CDC* pDC,
        CDockablePane* pBar,
        BOOL bActive,
        CRect rectCaption,
        CRect rectButtons)
    {
        static_cast<void>(pBar);
        static_cast<void>(bActive);
        static_cast<void>(rectButtons);
        CBrush brush(GetSysColor(COLOR_INACTIVEBORDER));
        pDC->FillRect(rectCaption, &brush);
        return static_cast<COLORREF>(-1);
    }

    virtual COLORREF OnDrawPropertySheetListItem(
        CDC* pDC,
        CMFCPropertySheet* pParent,
        CRect rect,
        BOOL bIsHighlihted,
        BOOL bIsSelected)
    {
        static_cast<void>(bIsHighlihted);
        static_cast<void>(bIsSelected);
        static_cast<void>(pParent);
        pDC->FillSolidRect(rect, RGB(0xFF, 0x00, 0x00));
        return RGB(0x00, 0xFF, 0x00);
    }

    // This is the are behind the ribbon where there are no categories
    virtual void OnDrawRibbonCategory(
        CDC* pDC,
        CMFCRibbonCategory* pCategory,
        CRect rectCategory)
    {
        static_cast<void>(pCategory);
        pDC->FillSolidRect(rectCategory, m_clrWindows10Bar);

        CPen pen(PS_SOLID, 1, GetSysColor(COLOR_3DLIGHT));
        pDC->SelectObject(pen);
        pDC->MoveTo(CPoint(rectCategory.left, rectCategory.top));
        pDC->LineTo(CPoint(rectCategory.right - 1, rectCategory.top));
    }

    virtual COLORREF OnFillRibbonMainPanelButton(
        CDC* pDC,
        CMFCRibbonButton* pButton)
    {
        CString text = pButton->GetText();
        if (!text.IsEmpty()) {
            pDC->FillSolidRect(pButton->GetRect(), m_clrWindows10Bar);
            return GetSysColor(COLOR_WINDOWTEXT);
        }
        return RGB(0xFE,0xFE,0xFF);
    }

    virtual void OnDrawRibbonMainPanelButtonBorder(
        CDC* pDC,
        CMFCRibbonButton* pButton
    )
    {
        CString text = pButton->GetText();
        if (!text.IsEmpty()) {
            pDC->SelectStockObject(BLACK_PEN);
            pDC->SelectStockObject(NULL_BRUSH);
            pDC->Rectangle(pButton->GetRect());
        }
    }

    virtual void OnDrawRibbonMainPanelFrame(
        CDC* pDC,
        CMFCRibbonMainPanel* pPanel,
        CRect rect
    )
    {
        pDC->FillSolidRect(rect, m_clrWindows10Bar);
    }

    virtual void OnFillRibbonMenuFrame(
        CDC* pDC,
        CMFCRibbonMainPanel* pPanel,
        CRect rect)
    {
        pDC->FillSolidRect(pPanel->GetRect(), RGB(0xFE, 0xFE, 0xFF));
    }


    virtual void OnDrawRibbonRecentFilesFrame(
        CDC* pDC,
        CMFCRibbonMainPanel* pPanel,
        CRect rect)
    {
        pDC->FillSolidRect(rect, RGB(0xFF, 0, 0));
    }

    virtual COLORREF OnFillRibbonButton(
        CDC* pDC,
        CMFCRibbonButton* pButton)
    {
        if (pButton->GetParentPanel() && pButton->GetParentPanel()->IsKindOf(RUNTIME_CLASS(CMFCRibbonMainPanel)))
        {
            // RHS of recent files does not have large icons
            if (pButton->IsLargeImage()) {
                pDC->FillSolidRect(pButton->GetRect(), RGB(0xFB, 0xFC, 0xFD));
                return GetSysColor(COLOR_WINDOWTEXT);
            }
        }
        return GetSysColor(COLOR_WINDOWTEXT);
    }

    virtual COLORREF OnDrawMenuLabel(
        CDC* pDC,
        CRect rect)
    {
        pDC->FillSolidRect(rect, m_clrWindows10Bar);
        return GetSysColor(COLOR_WINDOWTEXT);
    }

    // The ribbons tab at the top where the categories are
    virtual COLORREF OnDrawRibbonCategoryTab(
        CDC* pDC,
        CMFCRibbonTab* pTab,
        BOOL bIsActive)
    {
        // the background of the category tab
        if (bIsActive) {
            pDC->FillSolidRect(pTab->GetRect(), m_clrWindows10Bar);

            CPen pen(PS_SOLID,1,GetSysColor(COLOR_3DLIGHT));
            pDC->SelectObject(pen);
            pDC->MoveTo(CPoint(pTab->GetRect().left, pTab->GetRect().bottom));
            pDC->LineTo(CPoint(pTab->GetRect().left, pTab->GetRect().top));
            pDC->LineTo(CPoint(pTab->GetRect().right-1, pTab->GetRect().top));
            pDC->LineTo(CPoint(pTab->GetRect().right-1, pTab->GetRect().bottom));

            CPen pen2(PS_SOLID, 1, m_clrWindows10Bar);
            pDC->SelectObject(pen2);
            pDC->LineTo(CPoint(pTab->GetRect().left, pTab->GetRect().bottom));
        }
        else {
            CBrush brush(GetSysColor(COLOR_WINDOW));
            pDC->FillRect(pTab->GetRect(), &brush);

            CPen pen(PS_SOLID, 1, GetSysColor(COLOR_3DLIGHT));
            pDC->SelectObject(pen);
            pDC->MoveTo(CPoint(pTab->GetRect().left, pTab->GetRect().bottom));
            pDC->LineTo(CPoint(pTab->GetRect().right - 1, pTab->GetRect().bottom));

            pDC->SelectStockObject(BLACK_PEN);
        }
        // the color of the text on the tab
        if (bIsActive) {
            // the color of the selected tab text
            return GetSysColor(COLOR_WINDOWFRAME);
        }
        // the color of the non selected tab text
        return GetSysColor(COLOR_WINDOWFRAME);
    }

    virtual COLORREF OnDrawRibbonPanel(
        CDC* pDC,
        CMFCRibbonPanel* pPanel,
        CRect rectPanel,
        CRect rectCaption)
    {
        static_cast<void>(pPanel);
        // the color of the ribbon
        pDC->FillSolidRect(rectPanel, m_clrWindows10Bar);
        pDC->FillSolidRect(rectCaption, m_clrWindows10Bar);

        // draw the separator on the right hand side
        //CPen pen(PS_SOLID, 1, GetSysColor(COLOR_3DLIGHT));
        //pDC->SelectObject(pen);
        //pDC->MoveTo(rectPanel.right - 1, rectPanel.top + 2);
        //pDC->LineTo(rectPanel.right - 1, rectPanel.bottom);

        // This is the color of controls on the ribbon
        return GetSysColor(COLOR_WINDOWFRAME);
    }

    // this is the caption at the bottom on each panel
    virtual void OnDrawRibbonPanelCaption(
        CDC* pDC,
        CMFCRibbonPanel* pPanel,
        CRect rectCaption)
    {
        pDC->FillSolidRect(rectCaption, m_clrWindows10Bar);

        CString str = pPanel->GetName();

        if (!str.IsEmpty())
        {
            rectCaption.DeflateRect(1, 1);

            if ((rectCaption.Width() % 2) == 0)
            {
                rectCaption.right--;
            }

            rectCaption.OffsetRect(0, -1);

            COLORREF clrTextOld = pDC->SetTextColor(GetSysColor(COLOR_GRAYTEXT));
            pDC->DrawText(str, rectCaption, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
            pDC->SetTextColor(clrTextOld);
        }

        // draw the separator on the right hand side
        CPen pen(PS_SOLID, 1, GetSysColor(COLOR_3DLIGHT));
        pDC->SelectObject(pen);
        CRect panelRect = pPanel->GetRect();
        pDC->MoveTo(panelRect.right - 1, panelRect.top + 2);
        pDC->LineTo(panelRect.right - 1, panelRect.bottom - 2);
    }

    // The color behind the category tabs
    virtual COLORREF OnDrawRibbonTabsFrame(
        CDC* pDC,
        CMFCRibbonBar* pWndRibbonBar,
        CRect rectTab)
    {
        static_cast<void>(pWndRibbonBar);
        CBrush brush(GetSysColor(COLOR_WINDOW));
        pDC->FillRect(rectTab, &brush);

        // color return is reserved by Microsoft
        return static_cast<COLORREF>(-1);
    }

    virtual COLORREF OnDrawRibbonStatusBarPane(
        CDC* pDC,
        CMFCRibbonStatusBar* pBar,
        CMFCRibbonStatusBarPane* pPane)
    {
        static_cast<void>(pBar);
        // this is the color of the names
        CBrush brush(GetSysColor(COLOR_WINDOW));
        pDC->FillRect(pPane->GetRect(), &brush);

        // this is the text color
        return GetSysColor(COLOR_WINDOWTEXT);
    }

    virtual void OnFillBarBackground(
        CDC* pDC,
        CBasePane* pBar,
        CRect rectClient,
        CRect rectClip,
        BOOL bNCArea = FALSE)
    {
        static_cast<void>(bNCArea);
        static_cast<void>(rectClip);
        static_cast<void>(pBar);
        CBrush brush(GetSysColor(COLOR_WINDOW));
        pDC->FillRect(rectClient, &brush);
    }

    virtual BOOL OnEraseTabsFrame(
        CDC* pDC,
        CRect rect,
        const CMFCBaseTabCtrl* pTabWnd)
    {
        static_cast<void>(pTabWnd);
        CBrush brush(GetSysColor(COLOR_WINDOW));
        pDC->FillRect(rect, &brush);
        return TRUE;
    }

    virtual void OnDrawStatusBarSizeBox(
        CDC* pDC,
        CMFCStatusBar* pStatBar,
        CRect rectSizeBox)
    {
        static_cast<void>(pStatBar);
        CBrush brush(GetSysColor(COLOR_WINDOW));
        pDC->FillRect(rectSizeBox, &brush);
    }

    virtual void OnDrawTab(
        CDC* pDC,
        CRect rectTab,
        int iTab,
        BOOL bIsActive,
        const CMFCBaseTabCtrl* pTabWnd)
    {
        if (bIsActive) {
            pDC->FillSolidRect(rectTab, m_clrWindows10Bar);
        }
        else {
            pDC->FillSolidRect(rectTab, GetSysColor(COLOR_WINDOW));
        }

        CWnd *pTabWndCtrl = pTabWnd->GetTabWnd(iTab);

        CPen pen(PS_SOLID, 1, GetSysColor(COLOR_3DLIGHT));
        pDC->SelectObject(pen);

        if (pTabWnd->GetLocation() == CMFCBaseTabCtrl::LOCATION_BOTTOM)
        {
            pDC->MoveTo(CPoint(rectTab.left, rectTab.bottom));
            pDC->LineTo(CPoint(rectTab.right - 1, rectTab.bottom));
        }
        else {
            pDC->MoveTo(CPoint(rectTab.left, rectTab.top));
            pDC->LineTo(CPoint(rectTab.right - 1, rectTab.top));
        }

        // the right hand side of the tab
        pDC->MoveTo(CPoint(rectTab.right - 1, rectTab.top));
        pDC->LineTo(CPoint(rectTab.right - 1, rectTab.bottom));


        CString str;
        pTabWnd->GetTabLabel(iTab, str);

        if (!str.IsEmpty())
        {
            rectTab.DeflateRect(1, 1);

            if ((rectTab.Width() % 2) == 0)
            {
                rectTab.right--;
            }

            rectTab.OffsetRect(0, -1);

            COLORREF clrTextOld = pDC->SetTextColor(GetSysColor(COLOR_WINDOWFRAME));
            pDC->DrawText(str, rectTab, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_END_ELLIPSIS | DT_NOPREFIX);
            pDC->SetTextColor(clrTextOld);
        }
    }

    virtual void OnFillTab(
        CDC* pDC,
        CRect rectFill,
        CBrush* pbrFill,
        int iTab,
        BOOL bIsActive,
        const CMFCBaseTabCtrl* pTabWnd)
    {
        static_cast<void>(pTabWnd);
        static_cast<void>(bIsActive);
        static_cast<void>(iTab);
        static_cast<void>(pbrFill);
        CBrush brush(GetSysColor(COLOR_BTNSHADOW));
        pDC->FillRect(rectFill, &brush);
    }

    virtual void GetTabFrameColors(
        const CMFCBaseTabCtrl* pTabWnd,
        COLORREF& clrDark,
        COLORREF& clrBlack,
        COLORREF& clrHighlight,
        COLORREF& clrFace,
        COLORREF& clrDarkShadow,
        COLORREF& clrLight,
        CBrush*& pbrFace,
        CBrush*& pbrBlack)
    {
        static_cast<void>(pTabWnd);
        clrDark = GetSysColor(COLOR_BTNSHADOW);
        clrBlack = GetSysColor(COLOR_BTNSHADOW);
        clrHighlight = GetSysColor(COLOR_BTNSHADOW);
        clrFace = GetSysColor(COLOR_BTNSHADOW);
        clrDarkShadow = GetSysColor(COLOR_BTNSHADOW);
        clrLight = GetSysColor(COLOR_BTNSHADOW);

        pbrFace = &m_tabFaceBrush;
        pbrBlack = &m_tabBlackBrush;
    }

    virtual COLORREF GetTabTextColor(
        const CMFCBaseTabCtrl* pTabWnd,
        int iTab,
        BOOL bIsActive)
    {
        static_cast<void>(iTab);
        static_cast<void>(pTabWnd);
        static_cast<void>(bIsActive);
        return GetSysColor(COLOR_WINDOW);
    }

    virtual COLORREF GetPropertyGridGroupColor(CMFCPropertyGridCtrl* pPropList)
    {
        static_cast<void>(pPropList);
        return m_clrWindows10Bar;
    }

    virtual void OnDrawCaptionBarInfoArea(
        CDC* pDC,
        CMFCCaptionBar* pBar,
        CRect rect)
    {
        static_cast<void>(pBar);
        pDC->FillSolidRect(rect, RGB(0xFF, 0x00, 0x00));
    }

    virtual void OnDrawTabsButtonBorder(
        CDC* pDC,
        CRect& rect,
        CMFCButton* pButton,
        UINT uiState,
        CMFCBaseTabCtrl* pWndTab) override
    {
        static_cast<void>(pButton);
        static_cast<void>(rect);
        static_cast<void>(uiState);
        CBrush brush(GetSysColor(COLOR_BTNSHADOW));
        CRect tabRect;
        pWndTab->GetTabsRect(tabRect);
        pDC->FillRect(tabRect, &brush);
    }

    virtual void OnEraseTabsArea(
        CDC* pDC,
        CRect rect,
        const CMFCBaseTabCtrl* pTabWnd)
    {
        static_cast<void>(pTabWnd);
        pDC->FillSolidRect(rect, GetSysColor(COLOR_WINDOW));
    }

    void OnUpdateSystemColors() override
    {
        GetGlobalData()->clrBarFace = ::GetSysColor(COLOR_BTNFACE);
        GetGlobalData()->clrBtnFace = ::GetSysColor(COLOR_BTNFACE);

        GetGlobalData()->clrBarShadow = ::GetSysColor(COLOR_BTNSHADOW);
        GetGlobalData()->clrBtnShadow = ::GetSysColor(COLOR_BTNSHADOW);

        GetGlobalData()->clrBarDkShadow = ::GetSysColor(COLOR_3DDKSHADOW);
        GetGlobalData()->clrBtnDkShadow = ::GetSysColor(COLOR_3DDKSHADOW);

        GetGlobalData()->clrBarLight = ::GetSysColor(COLOR_3DLIGHT);
        GetGlobalData()->clrBtnLight = ::GetSysColor(COLOR_3DLIGHT);

        GetGlobalData()->clrBarHilite = ::GetSysColor(COLOR_BTNHIGHLIGHT);
        GetGlobalData()->clrBtnHilite = ::GetSysColor(COLOR_BTNHIGHLIGHT);

        GetGlobalData()->clrBarText = ::GetSysColor(COLOR_BTNTEXT);
        GetGlobalData()->clrBtnText = ::GetSysColor(COLOR_BTNTEXT);
        GetGlobalData()->clrGrayedText = ::GetSysColor(COLOR_GRAYTEXT);
        GetGlobalData()->clrWindowFrame = ::GetSysColor(COLOR_WINDOWFRAME);

        GetGlobalData()->clrHilite = ::GetSysColor(COLOR_HIGHLIGHT);
        GetGlobalData()->clrTextHilite = ::GetSysColor(COLOR_HIGHLIGHTTEXT);

        GetGlobalData()->clrBarWindow = ::GetSysColor(COLOR_WINDOW);
        GetGlobalData()->clrWindow = ::GetSysColor(COLOR_WINDOW);

        GetGlobalData()->clrWindowText = ::GetSysColor(COLOR_WINDOWTEXT);

        GetGlobalData()->clrCaptionText = ::GetSysColor(COLOR_CAPTIONTEXT);
        GetGlobalData()->clrMenuText = ::GetSysColor(COLOR_MENUTEXT);

        GetGlobalData()->clrActiveCaption = ::GetSysColor(COLOR_ACTIVECAPTION);
        GetGlobalData()->clrInactiveCaption = ::GetSysColor(COLOR_INACTIVECAPTION);

        GetGlobalData()->clrActiveCaptionGradient = ::GetSysColor(COLOR_GRADIENTACTIVECAPTION);
        GetGlobalData()->clrInactiveCaptionGradient = ::GetSysColor(COLOR_GRADIENTINACTIVECAPTION);

        GetGlobalData()->clrActiveBorder = ::GetSysColor(COLOR_ACTIVEBORDER);
        GetGlobalData()->clrInactiveBorder = ::GetSysColor(COLOR_INACTIVEBORDER);

        GetGlobalData()->clrInactiveCaptionText = ::GetSysColor(COLOR_INACTIVECAPTIONTEXT);
        GetGlobalData()->brBtnFace.DeleteObject();
        GetGlobalData()->brBtnFace.CreateSolidBrush(GetGlobalData()->clrBtnFace);

        GetGlobalData()->brBarFace.DeleteObject();
        GetGlobalData()->brBarFace.CreateSolidBrush(GetGlobalData()->clrBarFace);

        GetGlobalData()->brActiveCaption.DeleteObject();
        GetGlobalData()->brActiveCaption.CreateSolidBrush(GetGlobalData()->clrActiveCaption);

        GetGlobalData()->brInactiveCaption.DeleteObject();
        GetGlobalData()->brInactiveCaption.CreateSolidBrush(GetGlobalData()->clrInactiveCaption);

        GetGlobalData()->brHilite.DeleteObject();
        GetGlobalData()->brHilite.CreateSolidBrush(GetGlobalData()->clrHilite);

        GetGlobalData()->brBlack.DeleteObject();
        GetGlobalData()->brBlack.CreateSolidBrush(GetGlobalData()->clrBtnDkShadow);

        GetGlobalData()->brWindow.DeleteObject();
        GetGlobalData()->brWindow.CreateSolidBrush(GetGlobalData()->clrWindow);

        GetGlobalData()->penHilite.DeleteObject();
        GetGlobalData()->penHilite.CreatePen(PS_SOLID, 1, afxGlobalData.clrHilite);

        GetGlobalData()->penBarFace.DeleteObject();
        GetGlobalData()->penBarFace.CreatePen(PS_SOLID, 1, afxGlobalData.clrBarFace);

        GetGlobalData()->penBarShadow.DeleteObject();
        GetGlobalData()->penBarShadow.CreatePen(PS_SOLID, 1, afxGlobalData.clrBarShadow);

        // Windows 10 ribbon color
        m_clrWindows10Bar = RGB(0xF5, 0xF6, 0xF7);

        // Windows 10 file menu application button color
        m_clrWindows10ApplicationButton = RGB(0x19,0x79,0xCA);
    }

    virtual void OnDrawRibbonApplicationButton(
        CDC* pDC,
        CMFCRibbonButton* pButton)
    {
        pDC->FillSolidRect(pButton->GetRect(), m_clrWindows10ApplicationButton);
    }

    virtual void OnDrawDefaultRibbonImage(
        CDC* pDC,
        CRect rectImage,
        BOOL bIsDisabled,
        BOOL bIsPressed,
        BOOL bIsHighlighted)
    {
        static_cast<void>(pDC);
        static_cast<void>(rectImage);
        static_cast<void>(bIsDisabled);
        static_cast<void>(bIsPressed);
        static_cast<void>(bIsHighlighted);
        return;
    }

public:
    inline const COLORREF GetBackground() const
    {
        return m_crlBkgn;
    }

public:
    virtual BOOL IsToolbarRoundShape(CMFCToolBar* pToolBar) override
    {
        static_cast<void>(pToolBar);
        return FALSE;
    }


private:
    COLORREF	m_crlBkgn;

    CBrush m_tabFaceBrush;
    CBrush m_tabBlackBrush;

    COLORREF    m_clrWindows10Bar;
    COLORREF    m_clrWindows10ApplicationButton;
};

