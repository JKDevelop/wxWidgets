///////////////////////////////////////////////////////////////////////////////
// Name:        menuitem.h
// Purpose:     wxMenuItem class
// Author:      Vadim Zeitlin
// Modified by: 
// Created:     11.11.97
// RCS-ID:      $Id$
// Copyright:   (c) 1998 Vadim Zeitlin <zeitlin@dptmaths.ens-cachan.fr>
// Licence:     wxWindows license
///////////////////////////////////////////////////////////////////////////////

#ifndef   _MENUITEM_H
#define   _MENUITEM_H

#ifdef __GNUG__
#pragma interface "menuitem.h"
#endif

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

#include "wx/setup.h"

// an exception to the general rule that a normal header doesn't include other
// headers - only because ownerdrw.h is not always included and I don't want
// to write #ifdef's everywhere...
#if wxUSE_OWNER_DRAWN
#include  "wx/ownerdrw.h"
#endif

// ----------------------------------------------------------------------------
// wxMenuItem: an item in the menu, optionally implements owner-drawn behaviour
// ----------------------------------------------------------------------------
class WXDLLEXPORT wxMenuItem: public wxMenuItemBase
#if wxUSE_OWNER_DRAWN
                            , public wxOwnerDrawn
#endif
{
public:
    // ctor & dtor
    wxMenuItem(wxMenu *parentMenu = (wxMenu *)NULL,
               int id = wxID_SEPARATOR,
               const wxString& name = wxEmptyString,
               const wxString& help = wxEmptyString,
               bool isCheckable = FALSE,
               wxMenu *subMenu = (wxMenu *)NULL);
    virtual ~wxMenuItem();

    // override base class virtuals
    virtual void SetText(const wxString& strName);
    virtual wxString GetLabel() const;
    virtual void SetCheckable(bool checkable);

    virtual void Enable(bool bDoEnable = TRUE);
    virtual void Check(bool bDoCheck = TRUE);
    virtual bool IsChecked() const;

#if wxUSE_ACCEL
    virtual wxAcceleratorEntry *GetAccel() const;
#endif // wxUSE_ACCEL

    // unfortunately needed to resolve ambiguity between
    // wxMenuItemBase::IsCheckable() and wxOwnerDrawn::IsCheckable()
    bool IsCheckable() const { return wxMenuItemBase::IsCheckable(); }

    // the id for a popup menu is really its menu handle (as required by
    // ::AppendMenu() API), so this function will return either the id or the
    // menu handle depending on what we're
    int GetRealId() const;

	static MacBuildMenuString(StringPtr outMacItemText, SInt16 *outMacShortcutChar , UInt8 *outMacModifiers , const char *inItemName , bool useShortcuts ) ;

private:
    DECLARE_DYNAMIC_CLASS(wxMenuItem)
};

#endif  //_MENUITEM_H
