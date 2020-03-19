//
// Created by Kaung Zaw Htet on 2019-12-20.
//

#include <gui/grid_row/row_type_alphanumeric_level_3.h>
#include <model/type/alphanumeric_type.h>
void NameRow::setTypeOnGrid() {
   this->setEncodingCell();

    this->setComboBox(this->gTypeGrid->rowPointer, this->colPointer,this->arrGenderType,this->genderCount);


    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);



    ++(this->gTypeGrid->rowPointer);


    this->gTypeGrid->vecTypeNames.emplace_back(typeid(NameType).name());
}

void PangramRow::setTypeOnGrid() {
    this->setEncodingCell();
   
    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    ++(this->gTypeGrid->rowPointer);


    this->gTypeGrid->vecTypeNames.emplace_back(typeid(PangramType).name());
}



void DateRow::setTypeOnGrid() {
   this->setEncodingCell();

    //field for format
    this->setTextCtrl(this->gTypeGrid->rowPointer, this->colPointer,"%d-%b-%y");

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    ++(this->gTypeGrid->rowPointer);

    this->gTypeGrid->vecTypeNames.emplace_back(typeid(DateType).name());
}

void BooleanRow::setTypeOnGrid() {
   this->setEncodingCell();

    //field for boolean type
    this->setComboBox(this->gTypeGrid->rowPointer, this->colPointer,this->arrBoolType,this->boolCount);


    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    ++(this->gTypeGrid->rowPointer);


    this->gTypeGrid->vecTypeNames.emplace_back(typeid(BooleanType).name());
}

void CustomRow::setTypeOnGrid() {

   this->setEncodingCell();

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

//null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    ++(this->gTypeGrid->rowPointer);


    this->gTypeGrid->vecTypeNames.emplace_back(typeid(CustomType).name());

}

void NRCRow::setTypeOnGrid() {
    this->setEncodingCell();

    //NRC type field
    this->setComboBox(this->gTypeGrid->rowPointer, this->colPointer,this->arrNRCType,this->nrcCount);


    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    ++(this->gTypeGrid->rowPointer);


    this->gTypeGrid->vecTypeNames.emplace_back(typeid(NRCType).name());
}

