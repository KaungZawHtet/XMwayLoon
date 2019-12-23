//
// Created by Kaung Zaw Htet on 2019-12-18.
//

#ifndef XMWAYLOON_TYPE_LEVEL_3_H
#define XMWAYLOON_TYPE_LEVEL_3_H
#include <gui/type/type_level_2.h>
#include <gui/type/type_level_1.h>
#include <wx/wx.h>
#include <wx/grid.h>
#include <gui/data_generation/type_grid.h>
class NameType : public AlphaNumericType
{
public:
    explicit NameType(const wxString &tmpTypeName,TypeGrid *tmp_gTypeGrid)
    : AlphaNumericType(tmpTypeName,tmp_gTypeGrid) {}

    wxString arrGenderType[3] ={"ကျား", "မ", "ကျပန်း"};
    int genderCount = sizeof(arrGenderType)/ sizeof(arrGenderType[0]);
    void setTypeOnGrid() override;

};



class BooleanType : public AlphaNumericType
{

public:
    explicit BooleanType(const wxString &tmpTypeName,TypeGrid *tmp_gTypeGrid) 
    : AlphaNumericType(tmpTypeName,tmp_gTypeGrid) {}

    wxString arrBoolType[2] ={"မှား/မှန်", "၀/၁"};
    int boolCount = sizeof(arrBoolType)/ sizeof(arrBoolType[0]);
    void setTypeOnGrid() override;





};
class DateType :  public AlphaNumericType
{
public:
    explicit DateType(const wxString& tmp_TypeName,TypeGrid *tmp_gTypeGrid)
    : AlphaNumericType(tmp_TypeName,tmp_gTypeGrid){};
    void setTypeOnGrid() override;

};


class NRCType : public AlphaNumericType
{
public:
    explicit NRCType(const wxString &tmpTypeName,TypeGrid *tmp_gTypeGrid) 
    : AlphaNumericType(tmpTypeName,tmp_gTypeGrid) {}

    wxString arrNRCType[2] ={"နိုင်", "န"};
    int nrcCount = sizeof(arrNRCType)/ sizeof(arrNRCType[0]);
    void setTypeOnGrid() override;

};

class PangramType : public AlphaNumericType
{
public:
     explicit PangramType(const wxString &tmpTypeName,TypeGrid *tmp_gTypeGrid) 
     : AlphaNumericType(tmpTypeName,tmp_gTypeGrid) {}

    void setTypeOnGrid() override;

};




#endif //XMWAYLOON_TYPE_LEVEL_3_H
