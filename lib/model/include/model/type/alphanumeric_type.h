//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_ALPHANUMERIC_TYPE_H
#define XMWAYLOON_ALPHANUMERIC_TYPE_H

#include <parallel_hashmap/phmap.h>
#include <model/type/general_type.h>
#include <model/type/enums.h>



struct NameType : public AlphanumericType
{

    XML_RE::Gender gender;

    void setGender(std::string tmp)
    {
        this->gender=XML_RE::genderMap[tmp];

    }
};

struct PangramType : public AlphanumericType
{


};

struct NRCType : public AlphanumericType
{
    std::string type;


};

struct DateType : public AlphanumericType
{
    std::string format;


};

struct BooleanType : public AlphanumericType
{
    XML_RE::BoolType type;

    void setType(std::string tmp)
    {
        this->type=XML_RE::boolTypeMap[tmp];
    }

};

struct CustomType : public AlphanumericType
{


};


#endif //XMWAYLOON_ALPHANUMERIC_TYPE_H
