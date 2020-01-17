//
// Created by Kaung Zaw Htet on 2019-12-13.
//


#include <wx/wx.h>
#include <gui/data_generation/type_generation_container.h>
#include <gui/id.h>
#include <gui/data_generation/generate_page.h>

TypeGenerationContainer::TypeGenerationContainer(GeneratePage *tmp_gpParent, wxBoxSizer *tmp_bsMain)
: wxControl(tmp_gpParent, -1)
{

    this->gpParent= tmp_gpParent;
    this->bsMain=tmp_bsMain;
    //allocate Type Addition group
    this->bsAddType = new wxBoxSizer(wxHORIZONTAL);
    this->sl0 = new wxStaticLine(this->gpParent, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));
    this->bsAddTypeTitle = new wxBoxSizer(wxHORIZONTAL);
    this->stAddTypeTitle = new wxStaticText(this->gpParent, -1,
                                            wxT("Choose the type to generate : "));
    this->btnAddType = new wxButton(this->gpParent, BTN_ADD_TYPE_ID, wxT("+"));
    this->btnRemoveType = new wxButton(this->gpParent, BTN_REMOVE_TYPE_ID, wxT("-"));
    this->cbAddType = new wxComboBox(this->gpParent, CB_ADD_TYPE_ID,wxT("Choose Type:"),
            wxPoint(-1,-1),wxSize(-1,-1)
            ,objTypeLoader.totalCount,this->objTypeLoader.defaultType
            );
    this->cbAddType->SetEditable(false);

    //this->Connect(BTN_ADD_TYPE_ID,wxEVT_BUTTON,wxCommandEventHandler(TypeGenerationContainer::onAddType));
    this->gpParent->Bind(wxEVT_BUTTON, &TypeGenerationContainer::onRemoveType, this, BTN_REMOVE_TYPE_ID);
    this->gpParent->Bind(wxEVT_BUTTON, &TypeGenerationContainer::onAddType, this, BTN_ADD_TYPE_ID);

    //connect Type Addition's widgets to horrizontal BoxSizer
    this->bsAddTypeTitle->Add(this->stAddTypeTitle);
    this->bsAddType->Add(this->cbAddType, 2, wxRIGHT, 8);
    this->bsAddType->Add(this->btnAddType, 0);
    this->bsAddType->Add(this->btnRemoveType, 0);
    //---
    this->bsMain->Add(this->bsAddTypeTitle, 0, wxLEFT | wxTOP, 9); //title should be one less pixel
    this->bsMain->Add(this->bsAddType, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);


    //allocate and connect type grid
    this->bsTypeGrid = new wxBoxSizer(wxHORIZONTAL);
    this->gTypeGrid =new TypeGrid(this->gpParent);
    this->bsTypeGrid->Add(this->gTypeGrid, 2, wxRIGHT, 8);
    this->bsMain->Add(this->bsTypeGrid, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    this->bsMain->Add(sl0, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);


}





