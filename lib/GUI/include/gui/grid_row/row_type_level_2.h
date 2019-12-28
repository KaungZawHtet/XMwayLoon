//
// Created by Kaung Zaw Htet on 2019-12-18.
//

#ifndef XMWAYLOON_ROW_TYPE_LEVEL_2_H
#define XMWAYLOON_ROW_TYPE_LEVEL_2_H

#include <gui/grid_row/row_type_level_1.h>

class AlphaNumericRow : public Row
{
public:
    explicit AlphaNumericRow
    ( const wxString& tmpTypeName,TypeGrid *tmp_gTypeGrid)
    : Row(tmpTypeName,tmp_gTypeGrid) {

    }

    wxString arrEncodingType[3]= {"Unicode", "Zawgyi", "Random"};
    int encodeCount= sizeof(arrEncodingType)/ sizeof(arrEncodingType[0]);
    wxGridCellChoiceEditor *gcceEncoding
    = new wxGridCellChoiceEditor(encodeCount,arrEncodingType, false);
    void setEncodingCell();
};



class NumericRow: public Row
{
public:
    explicit NumericRow
    ( const wxString& tmpTypeName,TypeGrid *tmp_gTypeGrid)
    : Row(tmpTypeName,tmp_gTypeGrid) {}
    void setNoEncodingCell();

};




#endif //XMWAYLOON_ROW_TYPE_LEVEL_2_H
