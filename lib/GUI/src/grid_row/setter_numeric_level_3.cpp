//
// Created by Kaung Zaw Htet on 2019-12-19.
//
#include <gui/grid_row/row_type_numeric_level_3.h>
#include <wx/grid.h>
#include <model/type/numeric_type.h>

void NumberRow::setTypeOnGrid() {

    this->setNoEncodingCell();
    this->colPointer++;
    this->gTypeGrid->SetCellValue
    (this->gTypeGrid->rowPointer, this->colPointer, _(this->arrNumberRow[0]));
    this->gTypeGrid->SetCellEditor(this->gTypeGrid->rowPointer, this->colPointer
            ,new wxGridCellChoiceEditor(this->NumberRowCount,this->arrNumberRow));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("Prefix"));

    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("Postfix"));

    ++(this->gTypeGrid->rowPointer);

    NumberType objNumberType;
    this->gTypeGrid->vecTypes.emplace_back(objNumberType);

}

void PhNumberRow::setTypeOnGrid() {
    this->setNoEncodingCell();

    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrCountryCode[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(this->countryCodeCount,this->arrCountryCode));
    this->colPointer++;

    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrTelecom[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(this->telecomCount,this->arrTelecom));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);

    ++(this->gTypeGrid->rowPointer);

    PhNumberType objPhNumberType;
    this->gTypeGrid->vecTypes.emplace_back(objPhNumberType);
}






