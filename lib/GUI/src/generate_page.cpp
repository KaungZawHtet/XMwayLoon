
#include <limits>
#include <gui/generate_page.h>
#include <wx/wx.h>
#include <gui/type_generation_panel.h>
#include <wx/statline.h>
#include <gui/id.h>
#include <wx/grid.h>
#include <gui/output_amount_panel.h>



GeneratePage::GeneratePage(wxWindow *parent)
        : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1),
                  wxWS_EX_VALIDATE_RECURSIVELY) {
    //allocate main vertical BoxSizer
    this->bsMain = new wxBoxSizer(wxVERTICAL);
    this->pnlTypeGeneration= new TypeGenerationPanel(this, this->bsMain);

    this->pnlOutputAmountPanel= new OutputAmountPanel(this,this->bsMain);
   this->createOutputFormatGroup();

    this->pnlEncodeingTypePanel =new EncodingTypePanel(this,this->bsMain);

    this->createGenerateButton();

    this->SetSizer(this->bsMain);

}




void GeneratePage::createOutputFormatGroup() {
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

void GeneratePage::createGenerateButton() {
    this->bsGenerate = new wxBoxSizer(wxHORIZONTAL);
    this->btnGenerate = new wxButton(this, BTN_GENERATE_ID,
                                     wxT("Generate"));

    this->bsGenerate->Add(this->btnGenerate);
    this->bsMain->Add(this->bsGenerate, 0, wxALIGN_RIGHT | wxRIGHT | wxTOP, 10);

    this->Bind(wxEVT_BUTTON, &GeneratePage::onGenerate, this, BTN_GENERATE_ID);
}
void GeneratePage::onGenerate(wxCommandEvent &event) {
   // int a = this->scRecordNumber->GetValue();

   /* wxMessageDialog *dial = new wxMessageDialog(this,
            wxString::Format(wxT("%d"),a), wxT("Error")); dial->ShowModal();*/

}







