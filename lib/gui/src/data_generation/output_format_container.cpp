//
// Created by Kaung Zaw Htet on 2019-12-14.
//
#include <gui/id.h>
#include <wx/wx.h>
#include <gui/data_generation/output_format_container.h>
#include <wx/statline.h>
#include <wx/colour.h>
#include <gui/data_generation/generate_page.h>
OutputFormatContainer::OutputFormatContainer

(GeneratePage *tmp_gpParent, wxBoxSizer *tmp_bsMain) :
wxControl(tmp_gpParent,-1)
{

    this->bsMain=tmp_bsMain;
    this->gpParent=tmp_gpParent;

    //allocate Output format group
    this->sl2 = new wxStaticLine(this->gpParent, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));
    this->bsFormatType = new wxBoxSizer(wxHORIZONTAL);
    this->bsFormatTypeTitle = new wxBoxSizer(wxHORIZONTAL);
    this->stFormatTypeTitle = new wxStaticText(this->gpParent, -1,
                                               wxT("Output Format : "));
    this->stFormatTypeTitle->SetFont(this->gpParent->font->Bold());
    this->stError= new wxStaticText(this->gpParent, -1,
                                    wxT(""));
    this->cbCSV = new wxCheckBox(this->gpParent, CB_CSV_ID, wxT("CSV"));
    this->cbJSON = new wxCheckBox(this->gpParent, CB_JSON_ID, wxT("JSON"));
    this->cbXML = new wxCheckBox(this->gpParent, CB_XML_ID, wxT("XML"));
    this->cbHTML = new wxCheckBox(this->gpParent, CB_HTML_ID, wxT("HTML"));

    //connect Output format's widgets to horrizontal BoxSizer
    this->bsFormatTypeTitle->Add(this->stFormatTypeTitle);
    this->bsFormatTypeTitle->Add(this->stError,0, wxRIGHT, 8);
    this->bsFormatType->Add(this->cbCSV, 0, wxRIGHT, 100);
    this->bsFormatType->Add(this->cbJSON, 0, wxRIGHT, 100);
    this->bsFormatType->Add(this->cbXML, 0, wxRIGHT, 100);
    this->bsFormatType->Add(this->cbHTML, 0);
    //---
    this->bsMain->Add(this->bsFormatTypeTitle, 0, wxLEFT | wxTOP, 9);
    this->bsMain->Add(bsFormatType, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(sl2, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);


    this->gpParent->Bind
    (wxEVT_CHECKBOX, &OutputFormatContainer::onChecked, this, CB_CSV_ID);
    this->gpParent->Bind
    (wxEVT_CHECKBOX, &OutputFormatContainer::onChecked, this, CB_JSON_ID);
    this->gpParent->Bind
            (wxEVT_CHECKBOX, &OutputFormatContainer::onChecked, this, CB_XML_ID);
    this->gpParent->Bind
            (wxEVT_CHECKBOX, &OutputFormatContainer::onChecked, this, CB_HTML_ID);

}

void OutputFormatContainer::onChecked(wxCommandEvent &event) {

    if(this->cbCSV->IsChecked()) objOutputFormat.CSV= true;
    if(this->cbHTML->IsChecked()) objOutputFormat.HTML= true;
    if(this->cbJSON->IsChecked()) objOutputFormat.JSON= true;
    if(this->cbXML->IsChecked()) objOutputFormat.XML= true;

    event.Skip();

}