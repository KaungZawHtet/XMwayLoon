//
// Created by Kaung Zaw Htet on 2019-12-12.
//


#include <wx/wx.h>
#include <gui/data_generation/type_grid.h>


TypeGrid::TypeGrid(wxWindow *parent)
:wxGrid (parent,wxID_ANY,wxDefaultPosition)
{

    this->CreateGrid(6,5);
    this->EnableEditing(true);
    this->EnableScrolling(true,true);
    this->EnableGridLines(false);
    //this->EnableCellEditControl(true); //for combo
   // this->ShowCellEditControl(); //for combo
  //  this->EnableDragCell(false);


    this->SetColLabelValue(0, _("Type"));
    this->SetColLabelValue(1, _("Encoding"));
    this->SetColLabelValue(2, _("Type Specific Customization 1"));
    this->SetColLabelValue(3, _("Type Specific Customization 2 "));
    this->SetColLabelValue(4, _("Type Specific Customization 3"));

    this->HideRowLabels();

    this->SetColSize(0,100);
    this->SetColSize(1,90);
    this->SetColSize(2,175);
    this->SetColSize(3,175);
    this->SetColSize(4,182);


}