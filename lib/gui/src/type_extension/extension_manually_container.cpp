//
// Created by Kaung Zaw Htet on 2020-01-17.
//

#include <gui/type_extension/extension_manually_container.h>
#include <gui/id.h>



ExtensionManually_Container::ExtensionManually_Container
(wxWindow *tmp_wParent)
: wxPanel(tmp_wParent,-1)
{

    this->wParent= tmp_wParent;
    this->bsMain=new wxBoxSizer(wxVERTICAL);

    this->stTitle=new wxStaticText(this, -1,
                             wxT("Extend Type Manually : "));
    this->stTitle->SetFont(this->font->Bold());
    this->stRecord=new wxStaticText(this, -1,
                              wxT("Record :"));
    this->stRecord->Wrap(200);
    this->stTypeName=new wxStaticText(this, -1,
                             wxT("Type Name :"));
    this->stError=new wxStaticText(this, -1,
                                      wxT(""));
   // this->stTypeName->Wrap(200);
    this->btnExtend = new wxButton(this, BTN_EXTEND_MANUALLY_ID, wxT("Extend"));
    this->btnInsert= new wxButton(this, BTN_ADD_MANUALLY_ID, wxT("+"),wxDefaultPosition,wxSize(30,-1));
    this->btnRemove= new wxButton(this, BTN_REMOVE_MANUALLY_ID, wxT("-"),wxDefaultPosition,wxSize(30,-1));
    this-> tcRecord =new wxTextCtrl(this, TC_RECORD_MANUALLY_ID,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_PROCESS_ENTER);
    this->tcTypeName= new wxTextCtrl(this, TC_TYPE_NAME_MANUALLY_ID);

    this-> tcRecord->SetHint("Unicode or Zawgyi");


    ////ListBox Area open
    this->stUnicode=new wxStaticText(this, -1,
                                                wxT("Unicode : "));
    this->stZawgyi=new wxStaticText(this, -1,wxT("Zawgyi : "));

    this->lbUnicode=new wxListBox(this
            , LB_UNICODE_MANUALLY_ID,wxDefaultPosition,wxSize(220,200));
    this->lbZawgyi=new wxListBox(this
            , LB_ZAWGYI_MANUALLY_ID,wxDefaultPosition,wxSize(220,200));
    this->sl1= new wxStaticLine(this,-1);


    this->bsListBoxes=new wxBoxSizer(wxHORIZONTAL);
    this->bsUnicode=new wxBoxSizer(wxVERTICAL);
    this->bsZawgyi=new wxBoxSizer(wxVERTICAL);

    this->bsUnicode->Add(this->stUnicode,0,wxBOTTOM,6);
    this->bsUnicode->Add(this->lbUnicode);

    this->bsZawgyi->Add(this->stZawgyi,0,wxBOTTOM,6);
    this->bsZawgyi->Add(this->lbZawgyi);

    this->bsListBoxes->Add(this->bsUnicode);
    this->bsListBoxes->Add(this->bsZawgyi);

///// Listbox Area close

    this->Bind(wxEVT_BUTTON, &ExtensionManually_Container::onInsert, this, BTN_ADD_MANUALLY_ID);
    this->Bind(wxEVT_BUTTON, &ExtensionManually_Container::onRemove, this, BTN_REMOVE_MANUALLY_ID);
    this->Bind(wxEVT_LISTBOX, &ExtensionManually_Container::onSelect, this, LB_ZAWGYI_MANUALLY_ID);
    this->Bind(wxEVT_LISTBOX, &ExtensionManually_Container::onSelect, this, LB_UNICODE_MANUALLY_ID);
    this->Bind(wxEVT_TEXT_ENTER, &ExtensionManually_Container::onRecordEnter, this, TC_RECORD_MANUALLY_ID);
    this->Bind(wxEVT_BUTTON, &ExtensionManually_Container::onExtend, this, BTN_EXTEND_MANUALLY_ID);



    this->bsExtendBtn= new wxBoxSizer(wxHORIZONTAL);
    this->bsTitle= new wxBoxSizer(wxHORIZONTAL);
    this->bsRecordAddition= new wxBoxSizer(wxHORIZONTAL);
    this->bsTypeName= new wxBoxSizer(wxHORIZONTAL);


    this->bsExtendBtn->Add(this->btnExtend);
    this->bsTitle->Add(this->stTitle);
    this->bsTitle->Add(this->stError);
    this-> bsTypeName->Add(this->stTypeName,0,wxRIGHT,8);
    this->bsTypeName->Add(this->tcTypeName,2);
    this->bsRecordAddition->Add(this->stRecord,0,wxRIGHT,8);
    this-> bsRecordAddition->Add(this->tcRecord,2,wxRIGHT,8);
    this-> bsRecordAddition->Add(this->btnInsert);
    this-> bsRecordAddition->Add(this->btnRemove);

    this->bsMain->Add(this->bsTitle,0, wxLEFT | wxTOP, 9);
    this->bsMain->Add(this->bsTypeName,0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(this->bsRecordAddition,0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    this->bsMain->Add(this->bsListBoxes,0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(this->bsExtendBtn,0,  wxALIGN_RIGHT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(this->sl1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

    this->SetSizer(this->bsMain);


    zuconverter_open();


}

ExtensionManually_Container::~ExtensionManually_Container() {
    zuconverter_close();

}

