//
// Created by Kaung Zaw Htet on 2019-12-20.
//
#include <gui/type/type_level_1.h>
#include <gui/type/type_level_2.h>
#include <gui/data_generation/type_grid.h>
void Type::setNameCell() {

    if(gTypeGrid->GetNumberRows()< ((gTypeGrid->rowPointer)+1))
        //do it when poiner row is bigger than existing row number
    {
        gTypeGrid->AppendRows();

    }

    //No.
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer
            , _(std::to_string(this->gTypeGrid->rowPointer+1)));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;

    //Type Name
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer
            , _(this->typeName));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
}

void AlphaNumericType::setEncodingCell() {
    this->setNameCell();
    //Encoding
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrEncodingType[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(encodeCount,this->arrEncodingType));
    this->colPointer++;
    
}

void NumericType::setNoEncodingCell() {
    setNameCell();
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;



}