//
// Created by Kaung Zaw Htet on 2019-12-19.
//
#include <gui/grid_row/row_type_numeric_level_3.h>
#include <wx/grid.h>
#include <model/type/numeric_type.h>

void NRCRow::setTypeOnGrid() {
this->setNoEncodingCell();

    //NRC type field
    this->setComboBox(this->gTypeGrid->rowPointer, this->colPointer,this->arrNRCType,this->nrcCount);


    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    ++(this->gTypeGrid->rowPointer);


    this->gTypeGrid->vecTypeNames.emplace_back(typeid(NRCType).name());
}


void NumberRow::setTypeOnGrid() {

this->setNoEncodingCell();

    this->setComboBox(this->gTypeGrid->rowPointer, this->colPointer,this->arrNumberType,this->NumberRowCount);


    //prefix field
    this->setTextCtrl(this->gTypeGrid->rowPointer, this->colPointer,"Prefix");

    //post field
    this->setTextCtrl(this->gTypeGrid->rowPointer, this->colPointer,"Postfix");

    ++(this->gTypeGrid->rowPointer);


    this->gTypeGrid->vecTypeNames.emplace_back(typeid(NumberType).name());


}

void PhNumberRow::setTypeOnGrid() {
this->setNoEncodingCell();


    //country code field
    this->setComboBox(this->gTypeGrid->rowPointer, this->colPointer,this->arrCountryCodeMode,this->countryCodeCount);


    //telecom field
    this->setComboBox(this->gTypeGrid->rowPointer, this->colPointer,this->arrTelecom,this->telecomCount);


    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    ++(this->gTypeGrid->rowPointer);


    this->gTypeGrid->vecTypeNames.emplace_back(typeid(PhNumberType).name());

}






