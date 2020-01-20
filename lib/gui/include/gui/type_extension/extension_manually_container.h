//
// Created by Kaung Zaw Htet on 2020-01-17.
//

#ifndef XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H
#define XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H

#include <wx/wx.h>

class ExtendPage;
class ExtensionManually_Container : public wxControl
{
    ExtendPage *gpParent;

    wxButton *btnExtend;
    wxButton *btnAdd;

    wxStaticText *stTitle;
    wxStaticText *stTypeName;
    wxStaticText *stRecord;
    wxStaticText *stUnicode;
    wxStaticText *stZawgyi;

    wxTextCtrl *tcTypeName;
    wxTextCtrl *tcRecord;

    wxListBox *lbZawgyi;
    wxListBox *lbUnicode;


    wxBoxSizer *bsRecordAddition;
    wxBoxSizer *bsTitle;
    wxBoxSizer *bsTypeName;
    wxBoxSizer *bsExtendBtn;
    wxBoxSizer *bsUnicode;
    wxBoxSizer *bsZawgyi;
    wxBoxSizer *bsListBoxes;


    wxBoxSizer *bsMain;


    void onExtend(wxCommandEvent& event);

public:
    ExtensionManually_Container(ExtendPage *tmp_gpParent, wxBoxSizer *tmp_bsMain);



};


#endif //XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H
