//
// Created by Kaung Zaw Htet on 2019-12-19.
//

#include <gui/data_generation/type_generation_container.h>
#include <gui/grid_row/row_type_alphanumeric_level_3.h>
#include <gui/grid_row/row_type_numeric_level_3.h>
#include <gui/data_generation/generate_page.h>
#include <gui/data_generation/read_me_dialog.h>
void TypeGenerationContainer::onAddType(wxCommandEvent &event) {
  //  wxString tmp_typeName=this->objTypeLoader.vecAllTypes[0];;



  int index = this->cbAddType->GetSelection();


    switch (index)
    {
        case 0://Boolean
        {
            BooleanRow objBooleanRow(this->objTypeLoader.vecAllTypes[0], this->gTypeGrid);
            objBooleanRow.setTypeOnGrid();
        }
            break;

        case 1://Date
        {
            DateRow objDateRow(this->objTypeLoader.vecAllTypes[1], this->gTypeGrid);
            objDateRow.setTypeOnGrid();
        }
            break;

        case 2: //Name
        {
            NameRow objNameRow(this->objTypeLoader.vecAllTypes[2], this->gTypeGrid);
            objNameRow.setTypeOnGrid();
        }
            break;

        case 3://NRC
        {
            NRCRow objNRCRow(this->objTypeLoader.vecAllTypes[3], this->gTypeGrid);
            objNRCRow.setTypeOnGrid();
        }
            break;

        case 4: //Number
        {
            NumberRow objNumberRow(this->objTypeLoader.vecAllTypes[4], this->gTypeGrid);
            objNumberRow.setTypeOnGrid();
        }
            break;

        case 5: //Pangram
        {
            PangramRow objPangramRow(this->objTypeLoader.vecAllTypes[5], this->gTypeGrid);
            objPangramRow.setTypeOnGrid();
        }
            break;


        case 6://Ph Number
        {
            PhNumberRow objPhNumberRow(this->objTypeLoader.vecAllTypes[6], this->gTypeGrid);
            objPhNumberRow.setTypeOnGrid();
        }
            break;
        default:
        {
            if(index>0){
                CustomRow objCustomRow(this->objTypeLoader.vecAllTypes[index], this->gTypeGrid);
                objCustomRow.setTypeOnGrid();
            }


        }
            break;
    }



    event.Skip();
}

void TypeGenerationContainer::onRemoveType(wxCommandEvent &event) {


    if(this->gTypeGrid->rowPointer>0)
    {
        this->gTypeGrid->DeleteRows(this->gTypeGrid->rowPointer-1);
        this->gTypeGrid->vecTypeNames.pop_back();
        --(this->gTypeGrid->rowPointer);
    }

    event.Skip();
}

void TypeGenerationContainer::onReadMe(wxCommandEvent &event) {

    DataGenerationReadMeDialog panel("Read Me");


    event.Skip();

}
