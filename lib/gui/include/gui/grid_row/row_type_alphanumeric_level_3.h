//
// Created by Kaung Zaw Htet on 2019-12-18.
//

#ifndef XMWAYLOON_ROW_TYPE_ALPHANUMERIC_LEVEL_3_H
#define XMWAYLOON_ROW_TYPE_ALPHANUMERIC_LEVEL_3_H
#include <gui/grid_row/row_type_level_2.h>
#include <gui/grid_row/row_type_level_1.h>
#include <wx/wx.h>
#include <wx/grid.h>
#include <gui/data_generation/type_grid.h>

class NameRow : public AlphaNumericRow {
public:
    explicit NameRow(const wxString &tmpTypeName, TypeGrid *tmp_gTypeGrid)
            : AlphaNumericRow(tmpTypeName, tmp_gTypeGrid) {}

    wxString arrGenderType[3] = {"Male", "Female", "Random"};
    int genderCount = sizeof(arrGenderType) / sizeof(arrGenderType[0]);

    void setTypeOnGrid() override;

};


class BooleanRow : public AlphaNumericRow {

public:
    explicit BooleanRow(const wxString &tmpTypeName, TypeGrid *tmp_gTypeGrid)
            : AlphaNumericRow(tmpTypeName, tmp_gTypeGrid) {}

    wxString arrBoolType[2] = {"Mhar/Mhan", "0/1"};
    int boolCount = sizeof(arrBoolType) / sizeof(arrBoolType[0]);

    void setTypeOnGrid() override;


};

class DateRow : public AlphaNumericRow {
public:
    explicit DateRow(const wxString &tmp_TypeName, TypeGrid *tmp_gTypeGrid)
            : AlphaNumericRow(tmp_TypeName, tmp_gTypeGrid) {};

    void setTypeOnGrid() override;

};



class PangramRow : public AlphaNumericRow {
public:
    explicit PangramRow(const wxString &tmpTypeName, TypeGrid *tmp_gTypeGrid)
            : AlphaNumericRow(tmpTypeName, tmp_gTypeGrid) {}

    void setTypeOnGrid() override;

};

class CustomRow : public AlphaNumericRow {
public:
   
    explicit CustomRow(const wxString &tmpTypeName, TypeGrid *tmp_gTypeGrid)
            : AlphaNumericRow(tmpTypeName, tmp_gTypeGrid) {}

    void setTypeOnGrid() override;

};

class NRCRow : public AlphaNumericRow {
public:
    explicit NRCRow(const wxString &tmpTypeName, TypeGrid *tmp_gTypeGrid)
            : AlphaNumericRow(tmpTypeName, tmp_gTypeGrid) {}

    wxString arrNRCType[7] = {"N", "AC","NC", "V","M", "N","Random"};
    int nrcCount = sizeof(arrNRCType) / sizeof(arrNRCType[0]);

    void setTypeOnGrid() override;

};



#endif //XMWAYLOON_ROW_TYPE_ALPHANUMERIC_LEVEL_3_H
