//
// Created by Kaung Zaw Htet on 2019-12-20.
//

#include <gui/grid_row/row_type_alphanumeric_level_3.h>
#include <model/type/alphanumeric_type.h>
void NameRow::setTypeOnGrid() {
    this->setEncodingCell();

    this->colPointer++;
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

    // NameType objNameType;
    //  this->gTypeGrid->vecTypes.emplace_back(objNameType);
    this->gTypeGrid->vecTypeNames.emplace_back(typeid(NameType).name());
}

void PangramRow::setTypeOnGrid() {
    this->setEncodingCell();

    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);

    ++(this->gTypeGrid->rowPointer);

    // PangramType objPangramType;
    // this->gTypeGrid->vecTypes.emplace_back(objPangramType);
    this->gTypeGrid->vecTypeNames.emplace_back(typeid(PangramType).name());
}


void NRCRow::setTypeOnGrid() {
    this->setEncodingCell();

    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrNRCType[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(this->nrcCount,this->arrNRCType));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));

    ++(this->gTypeGrid->rowPointer);

    // NRCType objNRCType;
    //  this->gTypeGrid->vecTypes.emplace_back(objNRCType);
    this->gTypeGrid->vecTypeNames.emplace_back(typeid(NRCType).name());
}

void DateRow::setTypeOnGrid() {
    this->setEncodingCell();
    this->colPointer++;
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);

    ++(this->gTypeGrid->rowPointer);

    // DateType objDateType;
    //   this->gTypeGrid->vecTypes.emplace_back(objDateType);
    this->gTypeGrid->vecTypeNames.emplace_back(typeid(DateType).name());
}

void BooleanRow::setTypeOnGrid() {
    this->setEncodingCell();

    this->colPointer++;
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

    // BooleanType objBooleanType;
    // this->gTypeGrid->vecTypes.emplace_back(objBooleanType);
    this->gTypeGrid->vecTypeNames.emplace_back(typeid(BooleanType).name());
}

