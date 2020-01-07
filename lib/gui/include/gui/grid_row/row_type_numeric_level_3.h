//
// Created by Kaung Zaw Htet on 2019-12-18.
//

#ifndef XMWAYLOON_ROW_TYPE_NUMERIC_LEVEL_3_H
#define XMWAYLOON_ROW_TYPE_NUMERIC_LEVEL_3_H

#include <gui/grid_row/row_type_alphanumeric_level_3.h>
#include <gui/grid_row/row_type_numeric_level_3.h>
#include <wx/grid.h>
class NumberRow : public NumericRow
{
public:
    static const wxString arrNumberType[];//= {"Integer", "Float", "Rational"};
    static const int numberRowCount ; //= sizeof(arrNumberType) / sizeof(arrNumberType[0]);

    void setTypeOnGrid();
    NumberRow(wxString tmp_typeName,TypeGrid *tmp_gTypeGrid)
    : NumericRow(tmp_typeName,tmp_gTypeGrid) {}

};



class PhNumberRow: public  NumericRow
{
public:
    PhNumberRow(wxString tmp_typeName,TypeGrid *tmp_gTypeGrid) 
    : NumericRow(tmp_typeName,tmp_gTypeGrid) {}
    static const wxString arrTelecom[];//={"MPT","Telenor","Ooredoo","MyTel","Random"};
    static const int telecomCount;//= sizeof(arrTelecom)/ sizeof(arrTelecom[0]);
    static const wxString arrCountryCodeMode[];//[2]= {"+95 included", "no +95"};
    static const int countryCodeCount;//= sizeof(arrCountryCodeMode) / sizeof(arrCountryCodeMode[0]);

    void setTypeOnGrid();
};


#endif //XMWAYLOON_ROW_TYPE_NUMERIC_LEVEL_3_H
