//
// Created by Kaung Zaw Htet on 2020-01-17.
//

#ifndef XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H
#define XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H

#include <wx/wx.h>
#include <wx/statline.h>
class ExtendPage;
class ExtensionManually_Container : public wxPanel
{
    wxWindow *wParent;

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

    std::shared_ptr<wxFont> font= std::make_shared<wxFont>();

    wxBoxSizer *bsRecordAddition;
    wxBoxSizer *bsTitle;
    wxBoxSizer *bsTypeName;
    wxBoxSizer *bsExtendBtn;
    wxBoxSizer *bsUnicode;
    wxBoxSizer *bsZawgyi;
    wxBoxSizer *bsListBoxes;

    wxStaticLine *sl1;


    wxBoxSizer *bsMain;


    void onExtend(wxCommandEvent& event);

public:
    ExtensionManually_Container(wxWindow *tmp_wParent);



};


#endif //XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H
