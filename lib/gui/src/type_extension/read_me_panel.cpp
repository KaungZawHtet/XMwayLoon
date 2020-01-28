//
// Created by Kaung Zaw Htet on 2020-01-29.
//

#include <gui/type_extension/read_me_panel.h>

ReadMePanel::ReadMePanel(wxWindow *tmp_wParent) :
wxPanel(tmp_wParent,-1)
{

    this->bsMain =new wxBoxSizer(wxVERTICAL);
    this->stExplanation = new wxStaticText(this , -1, this->strExplanation.data());
    this->tcExample = new wxTextCtrl(this,-1,this->strJson.data()
    ,wxDefaultPosition,wxSize(-1,600),wxTE_MULTILINE);
    this->tcExample->SetEditable(false);

    this->bsMain->Add(this->stExplanation,0,wxLEFT|wxRIGHT |wxEXPAND|wxTOP, 10);
    this->bsMain->Add(this->tcExample,0,wxLEFT|wxRIGHT |wxEXPAND|wxTOP, 10);

    this->SetSizer(this->bsMain);


}