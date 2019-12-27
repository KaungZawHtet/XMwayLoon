//
// Created by Kaung Zaw Htet on 2019-12-19.
//

#include <gui/data_generation/type_generation_container.h>
#include <gui/type/alpha_numeric_level_3.h>
#include <gui/type/numeric_level_3.h>
void TypeGenerationContainer::onAddType(wxCommandEvent &event) {
  //  wxString tmp_typeName=this->objTypeLoader.defaultType[0];;
    switch (this->cbAddType->GetSelection())
    {
        case 0: //Number
        {
            NumberType objNumberType(this->objTypeLoader.defaultType[0],this->gTypeGrid);
            objNumberType.setTypeOnGrid();
        }
            break;
        case 1: //Name
        {
            NameType objNameType(this->objTypeLoader.defaultType[1],this->gTypeGrid);
            objNameType.setTypeOnGrid();
        }
        break;
        case 2: //Pangram
        {
            PangramType objPangramType(this->objTypeLoader.defaultType[2],this->gTypeGrid);
            objPangramType.setTypeOnGrid();
        }
            break;
        case 3://Boolean
        {
            BooleanType objBooleanType(this->objTypeLoader.defaultType[3],this->gTypeGrid);
            objBooleanType.setTypeOnGrid();
        }
            break;
        case 4://NRC
        {
            NRCType objNRCType(this->objTypeLoader.defaultType[4],this->gTypeGrid);
            objNRCType.setTypeOnGrid();
        }
            break;
        case 5://Date
        {
            DateType objDateType(this->objTypeLoader.defaultType[5],this->gTypeGrid);
            objDateType.setTypeOnGrid();
        }
            break;

        case 6://Ph Number
        {
            PhNumberType objPhNumberType(this->objTypeLoader.defaultType[7],this->gTypeGrid);
            objPhNumberType.setTypeOnGrid();
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