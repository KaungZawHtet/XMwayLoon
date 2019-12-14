//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#ifndef XMWAYLOON_OUTPUT_AMOUNT_PANEL_H
#define XMWAYLOON_OUTPUT_AMOUNT_PANEL_H
#include <wx/statline.h>
#include <wx/spinctrl.h>
#include <wx/wx.h>
#include <gui/type_grid.h>
class OutputAmountPanel : public wxPanel
{
public:
    OutputAmountPanel(wxWindow *tmp_parent,wxBoxSizer *tmp_bsMain);



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
    wxBoxSizer *bsMain;
    wxWindow *parent;

   // void onChangeOutputAmountType(wxCommandEvent& event);


};

#endif //XMWAYLOON_OUTPUT_AMOUNT_PANEL_H
