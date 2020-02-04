//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_ALPHANUMERIC_TYPE_H
#define XMWAYLOON_ALPHANUMERIC_TYPE_H

#include <parallel_hashmap/phmap.h>
#include <model/type/general_type.h>


enum class Gender {
    male = 1, female = 2, both = 3
};

inline phmap::flat_hash_map<std::string, Gender > genderMap =
        {
                { "ကျား",  Gender::male},
                { "မ", Gender::female},
                { "ကျပန်း",  Gender::both}
        };



struct NameType : public AlphanumericType
{

    Gender gender;
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
    std::string type;

};

struct CustomType : public AlphanumericType
{


};


#endif //XMWAYLOON_ALPHANUMERIC_TYPE_H
