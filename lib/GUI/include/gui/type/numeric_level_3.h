//
// Created by Kaung Zaw Htet on 2019-12-18.
//

#ifndef XMWAYLOON_NUMERIC_LEVEL_3_H
#define XMWAYLOON_NUMERIC_LEVEL_3_H

#include <gui/type/alpha_numeric_level_3.h>
#include <gui/type/numeric_level_3.h>
#include <wx/grid.h>
class NumberType : public NumericType
{
public:
    wxString arrNumberType[3]= {"Integer","Float","Rational"};
    int numberTypeCount= sizeof(arrNumberType)/ sizeof(arrNumberType[0]);

    void setTypeOnGrid();
    NumberType(wxString tmp_typeName,TypeGrid *tmp_gTypeGrid)
    : NumericType(tmp_typeName,tmp_gTypeGrid) {}

};

class IPAddressType : public NumericType
{
public:
    wxString arrIPType[2]= {"၁၂၈","၂၅၅"};
    int IPCount= sizeof(arrIPType)/ sizeof(arrIPType[0]);

    void setTypeOnGrid();
    IPAddressType(wxString tmp_typeName,TypeGrid *tmp_gTypeGrid)
    : NumericType(tmp_typeName,tmp_gTypeGrid){}


};

class PhNumberType: public  NumericType
{
public:
    PhNumberType(wxString tmp_typeName,TypeGrid *tmp_gTypeGrid) 
    : NumericType(tmp_typeName,tmp_gTypeGrid) {}
    wxString arrTelecom[5]={"MPT","Telenor","Ooredoo","MyTel","Random"};
    int telecomCount= sizeof(arrTelecom)/ sizeof(arrTelecom[0]);
    wxString arrCountryCode[2]= {"+95 included","no +95"};
    int countryCodeCount= sizeof(arrCountryCode)/ sizeof(arrCountryCode[0]);

    void setTypeOnGrid();
};


#endif //XMWAYLOON_NUMERIC_LEVEL_3_H
