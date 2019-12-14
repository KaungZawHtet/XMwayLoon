//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#include <wx/wx.h>
#include <gui/output_amount_panel.h>
#include <gui/id.h>
OutputAmountPanel::OutputAmountPanel(wxWindow *tmp_parent, wxBoxSizer *tmp_bsMain)
:wxPanel(tmp_parent,-1)
{
    //allocate Record Size group
    this->bsMain=tmp_bsMain;
    this->parent=tmp_parent;


    this->bsRecordSize = new wxBoxSizer(wxHORIZONTAL);
    this->sl1 = new wxStaticLine(this, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));
    this->bsRecordSizeTitle = new wxBoxSizer(wxHORIZONTAL);
    this->stRecordSizeTitle = new wxStaticText(this, -1,
                                               wxT("Output Amount : "),
                                               wxPoint(-1, -1), wxSize(-1, -1), wxRB_GROUP);
    this->rdRecordNumber = new wxRadioButton(this, RD_RECORD_NUMBER_ID,
                                             wxT("Record Number"));
    this->rdFileSize = new wxRadioButton(this, RD_FILE_SIZE_ID,
                                         wxT("File Size"));
    this->stRecordNumberUnit = new wxStaticText(this, -1,
                                                wxT("records"));
    this->stFileSizeUnit = new wxStaticText(this, -1,
                                            wxT("GB"));
    this->scRecordNumber = new wxSpinCtrl(this, wxID_ANY, wxString(""),
                                          wxPoint(-1, -1), wxSize(-1, -1), wxSP_ARROW_KEYS,
                                          1, 2147483647, 100);
    this->scFileSize = new wxSpinCtrlDouble(this, wxID_ANY, wxString(""),
                                            wxPoint(-1, -1), wxSize(-1, -1), wxSP_ARROW_KEYS,
                                            0.000001, 2147483647, 1);

    this->rdRecordNumber->SetValue(true);
   /* this->parent->Bind(wxEVT_RADIOBUTTON, &OutputAmountPanel::onChangeOutputAmountType,
               this); //TODO:: hander 'this' need to change if refactoring
*/

    //connect Record Size's widgets to horrizontal BoxSizer
    this->bsRecordSizeTitle->Add(this->stRecordSizeTitle, 0);
    this->bsRecordSize->Add(this->rdRecordNumber, 0, wxRIGHT, 20);
    this->bsRecordSize->Add(this->scRecordNumber, 0); //In case of cus, getBoxSizer should be called
    this->bsRecordSize->Add(this->stRecordNumberUnit, 0, wxRIGHT, 100);
    this->bsRecordSize->Add(this->rdFileSize, 0, wxRIGHT, 20);
    this->bsRecordSize->Add(this->scFileSize, 0);
    this->bsRecordSize->Add(this->stFileSizeUnit, 0);
    //---
    this->bsMain->Add(this->bsRecordSizeTitle, 0, wxLEFT | wxTOP, 9); //title should be one less pixel
    this->bsMain->Add(this->bsRecordSize, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(sl1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

}


/*
void OutputAmountPanel::onChangeOutputAmountType(wxCommandEvent &event) {
    int id = event.GetId();
    if (id == RD_FILE_SIZE_ID)  this->scRecordNumber->SetValue(100);
    if (id == RD_RECORD_NUMBER_ID) this->scFileSize->SetValue(1);
}
*/
