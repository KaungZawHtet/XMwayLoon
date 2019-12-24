//
// Created by Kaung Zaw Htet on 2019-12-14.
//
#include <gui/id.h>
#include <wx/wx.h>
#include <gui/data_generation/output_format_container.h>
#include <wx/statline.h>
OutputFormatContainer::OutputFormatContainer

(wxWindow *tmp_wParent, wxBoxSizer *tmp_bsMain) :
wxControl(tmp_wParent,-1)
{

    this->bsMain=tmp_bsMain;
    this->wParent=tmp_wParent;

    //allocate Output format group
    this->sl2 = new wxStaticLine(this->wParent, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));
    this->bsFormatType = new wxBoxSizer(wxHORIZONTAL);
    this->bsFormatTypeTitle = new wxBoxSizer(wxHORIZONTAL);
    this->stFormatTypeTitle = new wxStaticText(this->wParent, -1,
                                               wxT("Output Format : "));
    this->cbCSV = new wxCheckBox(this->wParent, CB_CSV_ID, wxT("CSV"));
    this->cbJSON = new wxCheckBox(this->wParent, CB_JSON_ID, wxT("JSON"));
    this->cbXML = new wxCheckBox(this->wParent, CB_XML_ID, wxT("XML"));
    this->cbHTML = new wxCheckBox(this->wParent, CB_HTML_ID, wxT("HTML"));

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


    this->wParent->Bind
    (wxEVT_CHECKBOX, &OutputFormatContainer::onChecked, this, CB_CSV_ID);
    this->wParent->Bind
    (wxEVT_CHECKBOX, &OutputFormatContainer::onChecked, this, CB_JSON_ID);
    this->wParent->Bind
            (wxEVT_CHECKBOX, &OutputFormatContainer::onChecked, this, CB_XML_ID);
    this->wParent->Bind
            (wxEVT_CHECKBOX, &OutputFormatContainer::onChecked, this, CB_HTML_ID);

}

void OutputFormatContainer::onChecked(wxCommandEvent &event) {

    if(this->cbCSV->IsChecked()) objOutputFormat.CSV= true;
    if(this->cbHTML->IsChecked()) objOutputFormat.HTML= true;
    if(this->cbJSON->IsChecked()) objOutputFormat.JSON= true;
    if(this->cbXML->IsChecked()) objOutputFormat.XML= true;

    event.Skip();

}