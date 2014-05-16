//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: UI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef UI_BASE_CLASSES_H
#define UI_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/panel.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/dataview.h>
#include <wx/imaglist.h>
#include <wx/bitmap.h>
#include <map>
#include <wx/icon.h>
#include <wx/pen.h>
#include <wx/aui/auibar.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/treelist.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/listbox.h>
#include <wx/button.h>

class SFTPStatusPageBase : public wxPanel
{
protected:
    wxDataViewListCtrl* m_dvListCtrl;

protected:
    virtual void OnContentMenu(wxDataViewEvent& event) { event.Skip(); }

public:
    SFTPStatusPageBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxTAB_TRAVERSAL);
    virtual ~SFTPStatusPageBase();
};


class SFTPImages : public wxImageList
{
protected:
    // Maintain a map of all bitmaps representd by their name
    std::map<wxString, wxBitmap> m_bitmaps;


protected:

public:
    SFTPImages();
    const wxBitmap& Bitmap(const wxString &name) const {
        if ( !m_bitmaps.count(name) )
            return wxNullBitmap;
        return m_bitmaps.find(name)->second;
    }
    virtual ~SFTPImages();
};


class SFTPTreeViewBase : public wxPanel
{
protected:
    enum {
        ID_ADD_BOOKMARK = 1001,
        ID_OPEN_ACCOUNT_MANAGER = 1002,
        ID_SFTP_CONNECT = 1003,
        ID_SFTP_DISCONNECT = 1004,
    };
protected:
    wxAuiToolBar* m_auibar;
    std::map<int, wxMenu*> m_dropdownMenus;
    wxChoice* m_choiceAccount;
    wxStaticText* m_staticText49;
    wxTextCtrl* m_textCtrlQuickJump;
    wxTreeListCtrl* m_treeListCtrl;

    virtual void ShowAuiToolMenu(wxAuiToolBarEvent& event);

protected:
    virtual void OnOpenAccountManager(wxCommandEvent& event) { event.Skip(); }
    virtual void OnConnect(wxCommandEvent& event) { event.Skip(); }
    virtual void OnConnectUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnDisconnect(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDisconnectUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnAddBookmark(wxAuiToolBarEvent& event) { event.Skip(); }
    virtual void OnAddBookmarkUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnGotoLocationUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnGotoLocation(wxCommandEvent& event) { event.Skip(); }
    virtual void OnItemExpanding(wxTreeListEvent& event) { event.Skip(); }
    virtual void OnItemActivated(wxTreeListEvent& event) { event.Skip(); }
    virtual void OnContextMenu(wxTreeListEvent& event) { event.Skip(); }

public:
    SFTPTreeViewBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxTAB_TRAVERSAL);
    virtual ~SFTPTreeViewBase();
};


class SFTPManageBookmarkDlgBase : public wxDialog
{
protected:
    wxListBox* m_listBoxBookmarks;
    wxButton* m_button70;
    wxStdDialogButtonSizer* m_stdBtnSizer58;
    wxButton* m_buttonOk;
    wxButton* m_buttonCancel;

protected:
    virtual void OnDelete(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDeleteUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    SFTPManageBookmarkDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Manage Bookmarks"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~SFTPManageBookmarkDlgBase();
};

#endif
