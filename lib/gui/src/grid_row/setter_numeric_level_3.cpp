//
// Created by Kaung Zaw Htet on 2019-12-19.
//
#include <gui/grid_row/row_type_numeric_level_3.h>
#include <wx/grid.h>
#include <model/type/numeric_type.h>

void NRCRow::setTypeOnGrid() {
    this->setNoEncodingCell();

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


void NumberRow::setTypeOnGrid() {

    this->setNoEncodingCell();
    this->colPointer++;
    this->gTypeGrid->SetCellValue
            (this->gTypeGrid->rowPointer, this->colPointer, _(this->arrNumberType[0]));
    this->gTypeGrid->SetCellEditor(this->gTypeGrid->rowPointer, this->colPointer
            ,new wxGridCellChoiceEditor(this->NumberRowCount,this->arrNumberType));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("Prefix"));

    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("Postfix"));

    ++(this->gTypeGrid->rowPointer);

    // NumberType objNumberType;
    // this->gTypeGrid->vecTypes.emplace_back(objNumberType);
    this->gTypeGrid->vecTypeNames.emplace_back(typeid(NumberType).name());


}

void PhNumberRow::setTypeOnGrid() {
    this->setNoEncodingCell();

    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrCountryCodeMode[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(this->countryCodeCount,this->arrCountryCodeMode));
    this->colPointer++;

    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrTelecom[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(this->telecomCount,this->arrTelecom));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);

    ++(this->gTypeGrid->rowPointer);

    // PhNumberType objPhNumberType;
    // this->gTypeGrid->vecTypes.emplace_back(objPhNumberType);
    this->gTypeGrid->vecTypeNames.emplace_back(typeid(PhNumberType).name());

}






