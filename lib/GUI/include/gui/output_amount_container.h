//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#ifndef XMWAYLOON_OUTPUT_AMOUNT_CONTAINER_H
#define XMWAYLOON_OUTPUT_AMOUNT_CONTAINER_H
#include <wx/statline.h>
#include <wx/spinctrl.h>
#include <wx/wx.h>
#include <gui/type_grid.h>
class OutputAmountContainer : public wxControl
{
public:


    wxBoxSizer *bsMain;
    wxWindow *parent;


    wxStaticText *stFormatTypeTitle;
    wxBoxSizer *bsFormatTypeTitle;
    wxBoxSizer *bsFormatType;
    wxCheckBox *cbCSV;
    wxCheckBox *cbJSON;
    wxCheckBox *cbXML;
    wxCheckBox *cbHTML;
    wxStaticLine *sl2;
    OutputAmountContainer(wxWindow *tmp_parent, wxBoxSizer *tmp_bsMain);


    wxStaticText *stRecordSizeTitle;
    wxBoxSizer *bsRecordSizeTitle;
    wxBoxSizer *bsRecordSize;
    wxRadioButton *rdRecordNumber;
    wxRadioButton *rdFileSize;
    wxSpinCtrl *scRecordNumber;
    wxSpinCtrlDouble *scFileSize;
    wxStaticText *stRecordNumberUnit;
    wxStaticText *stFileSizeUnit;
    wxStaticLine *sl1;

    void onChangeOutputAmountType(wxCommandEvent& event);


};

#endif //XMWAYLOON_OUTPUT_AMOUNT_CONTAINER_H
