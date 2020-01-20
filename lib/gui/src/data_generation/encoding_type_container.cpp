//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#include <wx/wx.h>
#include <gui/data_generation/encoding_type_container.h>
#include <gui/data_generation/generate_page.h>
#include <gui/id.h>
EncodingTypeContainer::EncodingTypeContainer(GeneratePage *tmp_gpParent, wxBoxSizer *tmp_bsMain)
:wxControl(tmp_gpParent,-1)
{
    this->bsMain=tmp_bsMain;

    this->gpParent=tmp_gpParent;

    //allocate Record Size group
    this->stEncodeTypeTitle = new wxStaticText(this->gpParent, -1,
                                               wxT("Encoding Type : "));
    this->stEncodeTypeTitle->SetFont(this->gpParent->font->Bold());
    this->sl3 = new wxStaticLine(this->gpParent, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));
    this->bsEncodeType = new wxBoxSizer(wxHORIZONTAL);
    this->bsEncodeTypeTitle = new wxBoxSizer(wxHORIZONTAL);
    this->rdUnicode = new wxRadioButton(this->gpParent, RD_UNICODE_ID,
                                        wxT("Unicode"),wxDefaultPosition,wxDefaultSize, wxRB_GROUP);
    this->rdZawgyi = new wxRadioButton(this->gpParent, RD_ZAWGYI_ID,
                                       wxT("Zawgyi"));
    this->rdRandom = new wxRadioButton(this->gpParent, RD_UNIFORM_RANDOM_ID,
                                       wxT("Uniform Random"));
    this->rdCustom = new wxRadioButton(this->gpParent, RD_CUSTOM_ID,
                                       wxT("Custom"));
    this->rdUnicode->SetValue(true);


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

    this->gpParent->Bind(wxEVT_RADIOBUTTON
            ,&EncodingTypeContainer::onTargetEncode,this);



}

//onTargetEncode at encoding_type_event.cpp
