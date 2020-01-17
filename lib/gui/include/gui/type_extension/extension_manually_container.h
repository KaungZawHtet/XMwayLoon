//
// Created by Kaung Zaw Htet on 2020-01-17.
//

#ifndef XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H
#define XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H

#include <wx/wx.h>

class ExtensionManually_Container : public wxControl
{
    wxWindow *wParent;

    wxStaticText *stTitle;
    wxButton *btnExtend;
    wxStaticText *stTypeName;
    wxStaticText *stRecord;

    wxTextCtrl *tcTypeName;
    wxTextCtrl *tcRecord;

    wxTextCtrl *tcZawgyi;
    wxTextCtrl *tcUnicode;
    wxListBox *lbZawgyi;
    wxListBox *lbUnicode;


    wxBoxSizer *bsFileExtender;
    wxBoxSizer *bsTitle;
    wxBoxSizer *bsExtendBtn;

    wxBoxSizer *bsMain;


    void onExtend(wxCommandEvent& event);

public:
    ExtensionManually_Container(wxWindow *tmp_wParent, wxBoxSizer *tmp_bsMain);



};


#endif //XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H
