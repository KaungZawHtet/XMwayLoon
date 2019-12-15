
#include <limits>
#include <gui/generate_page.h>
#include <wx/wx.h>
#include <gui/type_generation_container.h>
#include <wx/statline.h>
#include <gui/id.h>
#include <wx/grid.h>
#include <gui/output_amount_container.h>



GeneratePage::GeneratePage(wxWindow *parent)
        : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1),
                  wxWS_EX_VALIDATE_RECURSIVELY) {
    //allocate main vertical BoxSizer
    this->bsMain = new wxBoxSizer(wxVERTICAL);
    this->ctTypeGeneration= new TypeGenerationContainer(this, this->bsMain);

    this->ctOutputAmountContainer= new OutputAmountContainer(this, this->bsMain);
   this->ctOutputFormatContainer= new OutputFormatContainer(this,this->bsMain);

    this->ctEncodeingTypeContainer =new EncodingTypeContainer(this, this->bsMain);

    this->createGenerateButton();

    this->SetSizer(this->bsMain);

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







