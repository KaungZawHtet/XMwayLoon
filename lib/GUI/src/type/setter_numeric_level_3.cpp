//
// Created by Kaung Zaw Htet on 2019-12-19.
//
#include <gui/type/numeric_level_3.h>
#include <gui/type/alpha_numeric_level_3.h>
#include <wx/grid.h>


void NumberType::setTypeOnGrid() {

    this->setNoEncodingCell();
    this->colPointer++;
    this->gTypeGrid->SetCellValue
    (this->gTypeGrid->rowPointer, this->colPointer, _(this->arrNumberType[0]));
    this->gTypeGrid->SetCellEditor(this->gTypeGrid->rowPointer, this->colPointer
            ,new wxGridCellChoiceEditor(this->numberTypeCount,this->arrNumberType));
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("Prefix"));

    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("Postfix"));


    ++(this->gTypeGrid->rowPointer);

}

void PhNumberType::setTypeOnGrid() {
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
}






