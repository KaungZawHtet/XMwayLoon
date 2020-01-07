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
    (this->gTypeGrid->rowPointer, this->colPointer, _(this->arrNumberType[0]));
    this->gTypeGrid->SetCellEditor(this->gTypeGrid->rowPointer, this->colPointer
            ,new wxGridCellChoiceEditor(this->numberRowCount, this->arrNumberType));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("Prefix"));

    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("Postfix"));

    ++(this->gTypeGrid->rowPointer);

   // NumberType objNumberType;
   // this->gTypeGrid->vecTypes.emplace_back(objNumberType);
    this->gTypeGrid->vecTypeNames.emplace_back(typeid(NumberType).name());
}

const wxString NumberRow::arrNumberType [3]= {"Integer", "Float", "Rational"};
const int NumberRow::numberRowCount= sizeof(NumberRow::arrNumberType) / sizeof(NumberRow::arrNumberType[0]);



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

const wxString PhNumberRow::arrTelecom[5]={"MPT","Telenor","Ooredoo","MyTel","Random"};
const int PhNumberRow::telecomCount=sizeof(PhNumberRow::arrTelecom)/ sizeof(PhNumberRow::arrTelecom[0]);
const wxString PhNumberRow::arrCountryCodeMode[2]= {"+95 included", "no +95"};
const int PhNumberRow::countryCodeCount = sizeof(PhNumberRow::arrCountryCodeMode) / sizeof(PhNumberRow::arrCountryCodeMode[0]);








