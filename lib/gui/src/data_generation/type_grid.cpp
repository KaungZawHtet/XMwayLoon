//
// Created by Kaung Zaw Htet on 2019-12-12.
//


#include <wx/wx.h>
#include <gui/data_generation/type_grid.h>

#ifdef __APPLE__

#define TSO_COL_WIDTH 135


#elif __linux__

#define TSO_COL_WIDTH 170


#else

#define TSO_COL_WIDTH 135

#endif
TypeGrid::TypeGrid(wxWindow *wParent)
:wxGrid (wParent,wxID_ANY,wxDefaultPosition,wxSize(-1,147))
{

    this->CreateGrid(this->rows,this->columns);
    this->Fit();

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
    this->SetColLabelValue(7, _("Type Specific Option 4"));
    this->SetColLabelValue(8, _("Type Specific Option 5"));


    this->HideRowLabels();

    this->SetColSize(0,50);
    this->SetColSize(1,90);
    this->SetColSize(2,90);
    this->SetColSize(3,87); //field name
    this->SetColSize(4,TSO_COL_WIDTH);
    this->SetColSize(5,TSO_COL_WIDTH);
    this->SetColSize(6,TSO_COL_WIDTH);
    this->SetColSize(7,TSO_COL_WIDTH);
    this->SetColSize(8,TSO_COL_WIDTH);


    for (int row = 0; row < this->rows; ++row) {

        for (int col = 0; col <this->columns ; ++col) {
            this->SetReadOnly(row,col, true);
        }

    }




}