//
// Created by Kaung Zaw Htet on 2020-01-17.
//
#include <gui/type_extension/extension_by_file_container.h>
#include <gui/id.h>
#include <wx/dialog.h>
#include <gui/type_extension/extend_page.h>
ExtensionByFile_Container::ExtensionByFile_Container
(wxWindow *tmp_wParent)
: wxPanel(tmp_wParent,-1)
{

    this->wParent= tmp_wParent;
    this->bsMain=new wxBoxSizer(wxVERTICAL);
    //allocate Type Addition group
    this->bsTitle = new wxBoxSizer(wxHORIZONTAL);
    this->bsExtendBtn = new wxBoxSizer(wxHORIZONTAL);
    this->bsFileExtender = new wxBoxSizer(wxHORIZONTAL);
    this->sl0 = new wxStaticLine(this, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));

    this->stTitle = new wxStaticText(this, -1,
                                            wxT("Extend Type by json file : "));


    this->stTitle->SetFont(this->font->Bold());
    this->btnBrowse = new wxButton(this, BTN_BROWSE_BY_FILE_ID, wxT("Browse"));
    this->btnExtend = new wxButton(this, BTN_EXTEND_BY_FILE_ID, wxT("Extend"));
    this->btnReadMe = new wxButton(this, BTN_README_BY_FILE_ID, wxT("?"),wxDefaultPosition,wxSize(30,-1));


    this->tcPath = new wxTextCtrl(this, TC_PATH_BY_FILE_ID,wxT(""),
                                     wxPoint(-1,-1),wxSize(-1,-1));
    this->tcPath->SetEditable(false);

    //this->Connect(BTN_ADD_TYPE_ID,wxEVT_BUTTON,wxCommandEventHandler(TypeGenerationContainer::onAddType));
    this->wParent->Bind(wxEVT_BUTTON, &ExtensionByFile_Container::onBrowse, this, BTN_BROWSE_BY_FILE_ID);
    this->wParent->Bind(wxEVT_BUTTON, &ExtensionByFile_Container::onExtend, this, BTN_EXTEND_BY_FILE_ID);
    this->wParent->Bind(wxEVT_BUTTON, &ExtensionByFile_Container::onReadMe, this, BTN_README_BY_FILE_ID);

    //connect Type Addition's widgets to horrizontal BoxSizer
    this->bsTitle->Add(this->stTitle);
    this->bsFileExtender->Add(this->tcPath, 2, wxRIGHT, 8);
    this->bsFileExtender->Add(this->btnBrowse, 0);
    this->bsFileExtender->Add(this->btnReadMe, 0);
    this->bsExtendBtn->Add(this->btnExtend, 0);
    //---
    this->bsMain->Add(this->bsTitle, 0, wxLEFT | wxTOP, 9); //title should be one less pixel
    this->bsMain->Add(this->bsFileExtender, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(this->bsExtendBtn,0,  wxALIGN_RIGHT | wxRIGHT | wxTOP, 10);


    this->bsMain->Add(this->sl0, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

    this->SetSizer(this->bsMain);
}

