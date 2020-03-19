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
    wxString arrNumberType[3]= {"Integer", "Float", "Rational"};
    int NumberRowCount= sizeof(arrNumberType) / sizeof(arrNumberType[0]);

    void setTypeOnGrid();
    NumberRow(wxString tmp_typeName,TypeGrid *tmp_gTypeGrid)
            : NumericRow(tmp_typeName,tmp_gTypeGrid) {}

};



class PhNumberRow: public  NumericRow
{
public:
    PhNumberRow(wxString tmp_typeName,TypeGrid *tmp_gTypeGrid)
            : NumericRow(tmp_typeName,tmp_gTypeGrid) {}
    wxString arrTelecom[5]={"MPT","Telenor","Ooredoo","MyTel","Random"};
    int telecomCount= sizeof(arrTelecom)/ sizeof(arrTelecom[0]);
    wxString arrCountryCodeMode[4]= {"09...", "+959...","959...","random"};
    int countryCodeCount= sizeof(arrCountryCodeMode) / sizeof(arrCountryCodeMode[0]);

    void setTypeOnGrid();
};





#endif //XMWAYLOON_ROW_TYPE_NUMERIC_LEVEL_3_H
