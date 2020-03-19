//
// Created by Kaung Zaw Htet on 2019-12-19.
//
#include <gui/grid_row/row_type_numeric_level_3.h>
#include <wx/grid.h>
#include <model/type/numeric_type.h>



void NumberRow::setTypeOnGrid() {

this->setNoEncodingCell();

    //type field
    this->setComboBox(this->gTypeGrid->rowPointer, this->colPointer,this->arrNumberType,this->NumberRowCount);


    //prefix field
    this->setTextCtrl(this->gTypeGrid->rowPointer, this->colPointer,"Prefix");

    //post field
    this->setTextCtrl(this->gTypeGrid->rowPointer, this->colPointer,"Postfix");

    //min field
    this->setNumCtrl(this->gTypeGrid->rowPointer, this->colPointer,"10");

    //max field
    this->setNumCtrl(this->gTypeGrid->rowPointer, this->colPointer,"100");

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

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    //null field
    this->setBlankCell(this->gTypeGrid->rowPointer, this->colPointer);

    ++(this->gTypeGrid->rowPointer);


    this->gTypeGrid->vecTypeNames.emplace_back(typeid(PhNumberType).name());

}






