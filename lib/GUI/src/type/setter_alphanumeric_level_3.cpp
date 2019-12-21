//
// Created by Kaung Zaw Htet on 2019-12-20.
//

#include <gui/type/alpha_numeric_level_3.h>

void NameType::setTypeOnGrid() {
    this->setEncodingCell();

    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrGenderType[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(this->genderCount,this->arrGenderType));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);

    /*  this->gTypeGrid->SetCellEditor
              (this->gTypeGrid->row_pointer,this->gTypeGrid->col_pointer
                      ,new wxGridCellEnumEditor("Unicode,Zawgyi,Random"));
      this->gTypeGrid->SetCellRenderer
              (this->gTypeGrid->row_pointer,this->gTypeGrid->col_pointer
                      ,new wxGridCellEnumRenderer("Unicode,Zawgyi,Random"));*/

    // this->gTypeGrid->SetCellValue(this->gTypeGrid->row_pointer, 0, _("9"));

    ++(this->gTypeGrid->rowPointer);
}

void PangramType::setTypeOnGrid() {
    this->setEncodingCell();

    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);

    ++(this->gTypeGrid->rowPointer);
}


void NRCType::setTypeOnGrid() {
    this->setEncodingCell();

    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrNRCType[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(this->nrcCount,this->arrNRCType));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);


    ++(this->gTypeGrid->rowPointer);
}

void DateType::setTypeOnGrid() {
    this->setEncodingCell();
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);

    ++(this->gTypeGrid->rowPointer);
}

void BooleanType::setTypeOnGrid() {
    this->setEncodingCell();

    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrBoolType[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(this->boolCount,this->arrBoolType));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);


    ++(this->gTypeGrid->rowPointer);
}

