//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#ifndef XMWAYLOON_OUTPUT_AMOUNT_CONTAINER_H
#define XMWAYLOON_OUTPUT_AMOUNT_CONTAINER_H
#include <wx/statline.h>
#include <wx/spinctrl.h>
#include <wx/wx.h>
#include <gui/data_generation/type_grid.h>
class GeneratePage;
class OutputAmountContainer : public wxControl
{
public:


    wxBoxSizer *bsMain;

    GeneratePage *gpParent;


    wxStaticText *stFormatTypeTitle;
    wxBoxSizer *bsFormatTypeTitle;
    wxBoxSizer *bsFormatType;
    wxCheckBox *cbCSV;
    wxCheckBox *cbJSON;
    wxCheckBox *cbXML;
    wxCheckBox *cbHTML;
    wxStaticLine *sl2;
    OutputAmountContainer(GeneratePage *gpParent, wxBoxSizer *tmp_bsMain);


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


    int outputRecordAmount=100;
    bool isRecordAmount=true;
    double outputFileSize=1;

    void onChangeOutputAmountType(wxCommandEvent& event);


};

#endif //XMWAYLOON_OUTPUT_AMOUNT_CONTAINER_H
