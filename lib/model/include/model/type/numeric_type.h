//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_NUMERIC_TYPE_H
#define XMWAYLOON_NUMERIC_TYPE_H

#include <model/type/general_type.h>
#include <model/type/enums.h>
struct PhNumberType : public NumericType
{
    XML_RE::Telecom telecom;
    XML_RE::CountryCodeFlag countryCode;

    void setTelecom(std::string tmp)
    {
        this->telecom= XML_RE::telecomMap[tmp];
    }
    void setCountryCodeFlag(std::string tmp)
    {
        this->countryCode= XML_RE::countryCodeFlagMap[tmp];

    }


};

struct  NumberType : public NumericType
{
    XML_RE::NumberSystem system;
    XML_RE::NumberSign sign;
    std::string prefix;
    std::string postfix;
    unsigned long long min,max;

    void setSystem(std::string tmp){
        this->system= XML_RE::numSystemMap[tmp];
    }

    void setSign(std::string tmp){
        this->sign=XML_RE::numSignMap[tmp];
    }

    void setMax(std::string tmp) {

        this->max =stoull(tmp);
    }


    void setMin (std::string tmp)
    {
        this->min =stoull(tmp);

    }

};





#endif //XMWAYLOON_NUMERIC_TYPE_H
