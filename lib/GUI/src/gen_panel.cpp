
#include <limits>
#include <gui/gen_panel.h>
#include <wx/wx.h>
#include <gui/type_generation.h>
#include <wx/statline.h>
#include <gui/id.h>
#include <wx/grid.h>

BEGIN_EVENT_TABLE(GenPanel, wxPanel)
                EVT_BUTTON(BTN_GENERATE_ID, GenPanel::onGenerate)
END_EVENT_TABLE()


GenPanel::GenPanel(wxWindow *parent)
        : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1),
                  wxWS_EX_VALIDATE_RECURSIVELY) {
    //allocate main vertical BoxSizer
    this->bsMain = new wxBoxSizer(wxVERTICAL);
    this->createTypeAdditionGroup();
    this->createOutputAmountGroup();
    this->createOutputFormatGroup();
    this->createEncodeTypeGroup();
    this->createGenerateButton();

    this->SetSizer(this->bsMain);

}

void GenPanel::createTypeAdditionGroup() {
    this->objTypeGeneration= new TypeGeneration(this,this->bsMain);


}

void GenPanel::createOutputAmountGroup() {
    //allocate Record Size group
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
    this->Bind(wxEVT_RADIOBUTTON, &GenPanel::onChangeOutputAmountType,
               this); //TODO:: hander 'this' need to change if refactoring


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
void GenPanel::createOutputFormatGroup() {
    //allocate Output format group
    this->sl2 = new wxStaticLine(this, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));
    this->bsFormatType = new wxBoxSizer(wxHORIZONTAL);
    this->bsFormatTypeTitle = new wxBoxSizer(wxHORIZONTAL);
    this->stFormatTypeTitle = new wxStaticText(this, -1,
                                               wxT("Output Format : "));
    this->cbCSV = new wxCheckBox(this, wxID_ANY, wxT("CSV"));
    this->cbJSON = new wxCheckBox(this, wxID_ANY, wxT("JSON"));
    this->cbXML = new wxCheckBox(this, wxID_ANY, wxT("XML"));
    this->cbHTML = new wxCheckBox(this, wxID_ANY, wxT("HTML"));

    //connect Output format's widgets to horrizontal BoxSizer
    this->bsFormatTypeTitle->Add(this->stFormatTypeTitle);
    this->bsFormatType->Add(this->cbCSV, 0, wxRIGHT, 100);
    this->bsFormatType->Add(this->cbJSON, 0, wxRIGHT, 100);
    this->bsFormatType->Add(this->cbXML, 0, wxRIGHT, 100);
    this->bsFormatType->Add(this->cbHTML, 0);
    //---
    this->bsMain->Add(this->bsFormatTypeTitle, 0, wxLEFT | wxTOP, 9);
    this->bsMain->Add(bsFormatType, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(sl2, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);


}
void GenPanel::createEncodeTypeGroup() {

    //allocate Record Size group
    this->stEncodeTypeTitle = new wxStaticText(this, -1,
                                               wxT("Encoding Type : "));
    this->sl3 = new wxStaticLine(this, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));
    this->bsEncodeType = new wxBoxSizer(wxHORIZONTAL);
    this->bsEncodeTypeTitle = new wxBoxSizer(wxHORIZONTAL);
    this->rdUnicode = new wxRadioButton(this, wxID_ANY,
                                        wxT("Unicode"));
    this->rdZawgyi = new wxRadioButton(this, wxID_ANY,
                                       wxT("Zawgyi"));
    this->rdRandom = new wxRadioButton(this, wxID_ANY,
                                       wxT("Random"));
    this->rdCustom = new wxRadioButton(this, wxID_ANY,
                                       wxT("Custom"));


    //connect Record Size's widgets to horrizontal BoxSizer
    this->bsEncodeTypeTitle->Add(this->stEncodeTypeTitle);
    this->bsEncodeType->Add(this->rdUnicode, 0, wxRIGHT, 100);
    this->bsEncodeType->Add(this->rdZawgyi, 0, wxRIGHT, 100);
    this->bsEncodeType->Add(this->rdRandom, 0, wxRIGHT, 100);
    this->bsEncodeType->Add(this->rdCustom, 0);
    //---
    this->bsMain->Add(this->bsEncodeTypeTitle, 0, wxLEFT | wxTOP, 9);
    this->bsMain->Add(this->bsEncodeType, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(sl3, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
}
void GenPanel::createGenerateButton() {
    this->bsGenerate = new wxBoxSizer(wxHORIZONTAL);
    this->btnGenerate = new wxButton(this, BTN_GENERATE_ID,
                                     wxT("Generate"));

    this->bsGenerate->Add(this->btnGenerate);
    this->bsMain->Add(this->bsGenerate, 0, wxALIGN_RIGHT | wxRIGHT | wxTOP, 10);
}
void GenPanel::onGenerate(wxCommandEvent &event) {
    int a = this->scRecordNumber->GetValue();

    /*wxMessageDialog *dial = new wxMessageDialog(this,
            wxString::Format(wxT("%d"),a), wxT("Error")); dial->ShowModal();*/

}
void GenPanel::onChangeOutputAmountType(wxCommandEvent &event) {
    int id = event.GetId();
    if (id == RD_FILE_SIZE_ID)  this->scRecordNumber->SetValue(100);
    if (id == RD_RECORD_NUMBER_ID) this->scFileSize->SetValue(1);
}






