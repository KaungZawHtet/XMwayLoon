//
// Created by Kaung Zaw Htet on 2019-12-19.
//

#include <gui/data_generation/type_generation_container.h>
#include <gui/grid_row/row_type_alphanumeric_level_3.h>
#include <gui/grid_row/row_type_numeric_level_3.h>
void TypeGenerationContainer::onAddType(wxCommandEvent &event) {
  //  wxString tmp_typeName=this->objTypeLoader.defaultType[0];;
    switch (this->cbAddType->GetSelection())
    {
        case 0://Boolean
        {
            BooleanRow objBooleanRow(this->objTypeLoader.defaultType[0],this->gTypeGrid);
            objBooleanRow.setTypeOnGrid();
        }
            break;

        case 1://Date
        {
            DateRow objDateRow(this->objTypeLoader.defaultType[1],this->gTypeGrid);
            objDateRow.setTypeOnGrid();
        }
            break;

        case 2: //Name
        {
            NameRow objNameRow(this->objTypeLoader.defaultType[2],this->gTypeGrid);
            objNameRow.setTypeOnGrid();
        }
            break;

        case 3://NRC
        {
            NRCRow objNRCRow(this->objTypeLoader.defaultType[3],this->gTypeGrid);
            objNRCRow.setTypeOnGrid();
        }
            break;

        case 4: //Number
        {
            NumberRow objNumberRow(this->objTypeLoader.defaultType[4],this->gTypeGrid);
            objNumberRow.setTypeOnGrid();
        }
            break;

        case 5: //Pangram
        {
            PangramRow objPangramRow(this->objTypeLoader.defaultType[5],this->gTypeGrid);
            objPangramRow.setTypeOnGrid();
        }
            break;


        case 6://Ph Number
        {
            PhNumberRow objPhNumberRow(this->objTypeLoader.defaultType[6],this->gTypeGrid);
            objPhNumberRow.setTypeOnGrid();
        }
            break;
        default:
        {

        }
            break;
    }



    event.Skip();
}

void TypeGenerationContainer::onRemoveType(wxCommandEvent &event) {


    if(this->gTypeGrid->rowPointer>0)
    {
        this->gTypeGrid->DeleteRows(this->gTypeGrid->rowPointer-1);
        --(this->gTypeGrid->rowPointer);
    }

    event.Skip();
}