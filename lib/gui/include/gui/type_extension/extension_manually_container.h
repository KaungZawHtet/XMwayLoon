//
// Created by Kaung Zaw Htet on 2020-01-17.
//

#ifndef XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H
#define XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H
#include <myanmar_encoding_handler/parabaik.h>
#include <wx/wx.h>
#include <model/db/initializer.h>
#include <wx/statline.h>
class ExtendPage;
class ExtensionManually_Container : public wxPanel
{
    wxWindow *wParent;

    wxButton *btnExtend;
    wxButton *btnInsert;
    wxButton *btnRemove;

    wxStaticText *stTitle;
    wxStaticText *stTypeName;
    wxStaticText *stRecord;
    wxStaticText *stUnicode;
    wxStaticText *stZawgyi;
    wxStaticText *stError;

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

    int indexLB=0;
    std::vector<CustomTypeRecord> vecRecords;
    std::string strTypeName;




    void onExtend(wxCommandEvent& event);
    void onInsert(wxCommandEvent& event);
    void onRemove(wxCommandEvent& event);
    void onSelect(wxCommandEvent& event);
    void onRecordEnter(wxCommandEvent& event);
    void appendRecordList();

public:
    ExtensionManually_Container(wxWindow *tmp_wParent);
    ~ExtensionManually_Container() override;



};


#endif //XMWAYLOON_EXTENSION_MANUALLY_CONTAINER_H
