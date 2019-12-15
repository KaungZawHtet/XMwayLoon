//
// Created by Kaung Zaw Htet on 2019-12-13.
//

#include <gui/main_frame.h>
#include <gui/generate_page.h>
#include <wx/wx.h>
#include <gui/type_generation_container.h>
#include <gui/id.h>




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
    this->cbAddType = new wxComboBox(this->parent, CB_ADD_TYPE_ID, wxT("Number"));

    //this->Connect(BTN_ADD_TYPE_ID,wxEVT_BUTTON,wxCommandEventHandler(TypeGenerationContainer::onAddType));
     this->parent->Bind(wxEVT_BUTTON, &TypeGenerationContainer::onAddType, this, BTN_ADD_TYPE_ID);

    //connect Type Addition's widgets to horrizontal BoxSizer
    this->bsAddTypeTitle->Add(this->stAddTypeTitle);
    this->bsAddType->Add(this->cbAddType, 2, wxRIGHT, 8);
    this->bsAddType->Add(this->btnAddType, 0);
    //---
    this->bsMain->Add(this->bsAddTypeTitle, 0, wxLEFT | wxTOP, 9); //title should be one less pixel
    this->bsMain->Add(this->bsAddType, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);


    //allocate and connect type grid
    this->bsTypeGrid = new wxBoxSizer(wxHORIZONTAL);
    this->gTypeGrid =new TypeGrid(this->parent);
    this->bsTypeGrid->Add(this->gTypeGrid, 2, wxRIGHT, 8);
    this->bsMain->Add(this->bsTypeGrid, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(sl0, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    ///




}

void TypeGenerationContainer::onAddType(wxCommandEvent &event) {


    if(this->gTypeGrid->GetNumberRows()< ((this->gTypeGrid->row_pointer)+1))
    {
        this->gTypeGrid->AppendRows();

    }
    wxString choices[3]={wxT("TEST"), wxT("TEST2"), wxT("TEST3")};
    this->gTypeGrid->SetCellValue(this->gTypeGrid->row_pointer, this->gTypeGrid->col_pointer, _(choices[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->row_pointer,this->gTypeGrid->col_pointer
                    ,new wxGridCellChoiceEditor(3,choices,false));


    // this->gTypeGrid->SetCellValue(this->gTypeGrid->row_pointer, 0, _("9"));
    ++(this->gTypeGrid->row_pointer);
}




