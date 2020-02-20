//
// Created by Kaung Zaw Htet on 2019-12-20.
//
#include <gui/grid_row/row_type_level_1.h>
#include <gui/grid_row/row_type_level_2.h>
#include <gui/data_generation/type_grid.h>
void Row::setNameCell() {

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
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer,true);
    this->colPointer++;


}

void Row::setBlankCell(int &rowPointer, int &colPointer) {
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);

}

void Row::setComboBox(int &rowPointer, int &colPointer, wxString *arr, int &size) {

    this->colPointer++;
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer, this->colPointer, false);
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(arr[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(size,arr));

}

void Row::setTextCtrl(int &rowPointer,int &colPointer,wxString prompt) {
    this->colPointer++;
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(prompt));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer, this->colPointer, false);

}



void Row::setNumCtrl(int &rowPointer, int &colPointer,wxString value) {
    this->colPointer++;
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer, this->colPointer, false);
   // this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(arr[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellNumberEditor);
    this->gTypeGrid->SetCellRenderer
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellNumberRenderer);
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer,this->colPointer
            ,_(value));


}


void AlphaNumericRow::setEncodingCell() {
    this->setNameCell();
    //Encoding
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer, this->colPointer, false);
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _(this->arrEncodingType[0]));
    this->gTypeGrid->SetCellEditor
            (this->gTypeGrid->rowPointer,this->colPointer
                    ,new wxGridCellChoiceEditor(encodeCount,this->arrEncodingType));
    this->colPointer++;

    //field Name
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer, this->colPointer, false); //for field name
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer
            ,_("My field")+wxString::Format(wxT("%d"), 1+this->gTypeGrid->rowPointer));

}

void NumericRow::setNoEncodingCell() {
    setNameCell();
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer, _("-"));
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer,this->colPointer);
    this->colPointer++;

    //field Name
    this->gTypeGrid->SetReadOnly(this->gTypeGrid->rowPointer, this->colPointer, false); //for field name
    this->gTypeGrid->SetCellValue(this->gTypeGrid->rowPointer, this->colPointer
            , _("My field")+wxString::Format(wxT("%d"), 1+this->gTypeGrid->rowPointer));



}