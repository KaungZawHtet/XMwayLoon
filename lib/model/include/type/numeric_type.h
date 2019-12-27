//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_NUMERIC_TYPE_H
#define XMWAYLOON_NUMERIC_TYPE_H

#include <type/general_type.h>

struct PhNumberType : public NumericType
{
    std::string telecom;
    std::string countryCode;


};

struct  NumberType : public NumericType
{
    std::string type;
    std::string prefix;
    std::string postfix;

};





#endif //XMWAYLOON_NUMERIC_TYPE_H
