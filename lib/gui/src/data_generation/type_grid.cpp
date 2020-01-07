//
// Created by Kaung Zaw Htet on 2019-12-12.
//


#include <wx/wx.h>
#include <gui/data_generation/type_grid.h>


TypeGrid::TypeGrid(wxWindow *wParent)
:wxGrid (wParent,wxID_ANY,wxDefaultPosition)
{

    this->CreateGrid(6,7);
    this->EnableEditing(true);
    this->EnableScrolling(true,true);
    this->EnableGridLines(false);
    //this->EnableCellEditControl(true); //for combo
   // this->ShowCellEditControl(); //for combo
  //  this->EnableDragCell(false);


    this->SetColLabelValue(0, _("No."));
    this->SetColLabelValue(1, _("Type"));
    this->SetColLabelValue(2, _("Encoding"));
    this->SetColLabelValue(3, _("Field Name"));
    this->SetColLabelValue(4, _("Type Specific Option 1"));
    this->SetColLabelValue(5, _("Type Specific Option 2"));
    this->SetColLabelValue(6, _("Type Specific Option 3"));


    this->HideRowLabels();

    this->SetColSize(0,50);
    this->SetColSize(1,90);
    this->SetColSize(2,90);
    this->SetColSize(3,87); //field name
    this->SetColSize(4,135);
    this->SetColSize(5,135);
    this->SetColSize(6,135);



}