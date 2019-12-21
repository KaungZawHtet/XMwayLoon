//
// Created by Kaung Zaw Htet on 2019-12-18.
//

#ifndef XMWAYLOON_TYPE_LEVEL_2_H
#define XMWAYLOON_TYPE_LEVEL_2_H

#include <gui/type/type_level_1.h>

class AlphaNumericType : public Type
{
public:
    explicit AlphaNumericType
    ( const wxString& tmpTypeName,TypeGrid *tmp_gTypeGrid)
    : Type(tmpTypeName,tmp_gTypeGrid) {

    }

    wxString arrEncodingType[3]= {"Unicode", "Zawgyi", "Random"};
    int encodeCount= sizeof(arrEncodingType)/ sizeof(arrEncodingType[0]);
    wxGridCellChoiceEditor *gcceEncoding
    = new wxGridCellChoiceEditor(encodeCount,arrEncodingType, false);
    void setEncodingCell();
};



class NumericType: public Type
{
public:
    explicit NumericType
    ( const wxString& tmpTypeName,TypeGrid *tmp_gTypeGrid)
    : Type(tmpTypeName,tmp_gTypeGrid) {}
    void setNoEncodingCell();

};




#endif //XMWAYLOON_TYPE_LEVEL_2_H
