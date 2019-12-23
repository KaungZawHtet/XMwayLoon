//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_ALPHA_NUMERIC_TYPE_H
#define XMWAYLOON_ALPHA_NUMERIC_TYPE_H

#include <type/general_type.h>

struct NameType : public AlphanumericType
{

    std::string gender;
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
    std::string type;


};

struct BooleanType : public AlphanumericType
{
    std::string type;

};




#endif //XMWAYLOON_ALPHA_NUMERIC_TYPE_H
