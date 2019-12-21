//
// Created by Kaung Zaw Htet on 2019-12-13.
//

#include <gui/main_frame.h>
#include <gui/data_generation/generate_page.h>
#include <wx/wx.h>
#include <gui/data_generation/type_generation_container.h>
#include <gui/id.h>
#include <logic/type_loader.h>





TypeGenerationContainer::TypeGenerationContainer(wxWindow *tmp_parent, wxBoxSizer *tmp_bsMain)
: wxPanel(tmp_parent, -1)
{

    this->parent= tmp_parent;
    this->bsMain=tmp_bsMain;
    //allocate Type Addition group
    this->bsAddType = new wxBoxSizer(wxHORIZONTAL);
    this->sl0 = new wxStaticLine(this->parent, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));
    this->bsAddTypeTitle = new wxBoxSizer(wxHORIZONTAL);
    this->stAddTypeTitle = new wxStaticText(this->parent, -1,
                                            wxT("Choose the type to generate : "));
    this->btnAddType = new wxButton(this->parent, BTN_ADD_TYPE_ID, wxT("+"));
    this->btnRemoveType = new wxButton(this->parent, BTN_REMOVE_TYPE_ID, wxT("-"));
    this->cbAddType = new wxComboBox(this->parent, CB_ADD_TYPE_ID,wxT("Choose Type:"),
            wxPoint(-1,-1),wxSize(-1,-1)
            ,objTypeLoader.totalCount,this->objTypeLoader.defaultType
            );
    this->cbAddType->SetEditable(false);

    //this->Connect(BTN_ADD_TYPE_ID,wxEVT_BUTTON,wxCommandEventHandler(TypeGenerationContainer::onAddType));
    this->parent->Bind(wxEVT_BUTTON, &TypeGenerationContainer::onRemoveType, this, BTN_REMOVE_TYPE_ID);
    this->parent->Bind(wxEVT_BUTTON, &TypeGenerationContainer::onAddType, this, BTN_ADD_TYPE_ID);

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
    this->gTypeGrid =new TypeGrid(this->parent);
    this->bsTypeGrid->Add(this->gTypeGrid, 2, wxRIGHT, 8);
    this->bsMain->Add(this->bsTypeGrid, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(sl0, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);


}





