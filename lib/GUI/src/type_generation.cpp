//
// Created by Kaung Zaw Htet on 2019-12-13.
//

#include <gui/main_frame.h>
#include <gui/gen_panel.h>
#include <wx/wx.h>
#include <gui/type_generation.h>
#include <gui/id.h>

/*BEGIN_EVENT_TABLE(GenPanel, wxPanel)
                EVT_BUTTON(BTN_ADD_TYPE_ID, TypeGeneration::onAddType)
END_EVENT_TABLE()*/


TypeGeneration::TypeGeneration(wxWindow *parent,wxBoxSizer *tmp_bsMain)//:wxWindow(parent,-1)
{
    this->parent= parent;
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

    //connect Type Addition's widgets to horrizontal BoxSizer
    this->bsAddTypeTitle->Add(this->stAddTypeTitle);
    this->bsAddType->Add(this->cbAddType, 2, wxRIGHT, 8);
    this->bsAddType->Add(this->btnAddType, 0);
    //---
    this->bsMain->Add(this->bsAddTypeTitle, 0, wxLEFT | wxTOP, 9); //title should be one less pixel
    this->bsMain->Add(this->bsAddType, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);


    //allocate and connect type listctrl
    this->bsTypeGrid = new wxBoxSizer(wxHORIZONTAL);
    // this->lcTypeList = new TypeList(this);
    this->gTypeGrid =new TypeGrid(this->parent);
    this->bsTypeGrid->Add(this->gTypeGrid, 2, wxRIGHT, 8);
    this->bsMain->Add(this->bsTypeGrid, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(sl0, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    ///
}

void TypeGeneration::onAddType(wxCommandEvent &event) {

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

/*
bool TypeGeneration::AcceptsFocus() const {
    return true;
}

bool TypeGeneration::AcceptsFocusFromKeyboard() const {
    return true;
}*/
