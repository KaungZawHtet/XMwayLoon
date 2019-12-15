//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#include <wx/wx.h>
#include <gui/encoding_type_container.h>

EncodingTypeContainer::EncodingTypeContainer(wxWindow *tmp_parent, wxBoxSizer *tmp_bsMain)
:wxControl(tmp_parent,-1)
{
    this->bsMain=tmp_bsMain;
    this->parent=tmp_parent;
    //allocate Record Size group
    this->stEncodeTypeTitle = new wxStaticText(this->parent, -1,
                                               wxT("Encoding Type : "));
    this->sl3 = new wxStaticLine(this->parent, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));
    this->bsEncodeType = new wxBoxSizer(wxHORIZONTAL);
    this->bsEncodeTypeTitle = new wxBoxSizer(wxHORIZONTAL);
    this->rdUnicode = new wxRadioButton(this->parent, wxID_ANY,
                                        wxT("Unicode"),wxDefaultPosition,wxDefaultSize, wxRB_GROUP);
    this->rdZawgyi = new wxRadioButton(this->parent, wxID_ANY,
                                       wxT("Zawgyi"));
    this->rdRandom = new wxRadioButton(this->parent, wxID_ANY,
                                       wxT("Random"));
    this->rdCustom = new wxRadioButton(this->parent, wxID_ANY,
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

