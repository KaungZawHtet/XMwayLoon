//
// Created by Kaung Zaw Htet on 2020-02-05.
//

#ifndef XMWAYLOON_ENUMS_H
#define XMWAYLOON_ENUMS_H
#include <parallel_hashmap/phmap.h>



namespace XML_RE {


    //Encoding
enum class Encoding {unicode=1,zawgyi=2,random=3};

static   phmap::flat_hash_map<std::string, Encoding> encodingMap =
        {
                { "Unicode",  Encoding::unicode},
                { "Zawgyi", Encoding::zawgyi},
                { "Random",  Encoding::random}
        };






//For Name Randomizer

enum class Gender {
    male = 1, female = 2, random = 3
};

 static  phmap::flat_hash_map<std::string, Gender > genderMap =
        {
                { "Male",  Gender::male},
                { "Female", Gender::female},
                { "Random",  Gender::random}
        };

//For Bool Randomizer


enum class BoolType{num=1,alpha=2};
static  phmap::flat_hash_map<std::string, BoolType > boolTypeMap =
        {
                { "Mhar/Mhan",  BoolType::alpha},
                { "0/1", BoolType::num},

        };


//Phone Number

    enum class CountryCodeFlag {
        zero_nine, plus_nine_five, nine_five, random
    };
    enum class Telecom {
        MPT, Telenor, Ooredoo, Mytel ,Random
    };
    // TODO:: not sync with actual randomizer
    //{"MPT","Telenor","Ooredoo","MyTel","Random"};
    //{"+95 included", "no +95","random"}
    static  phmap::flat_hash_map<std::string, CountryCodeFlag > countryCodeFlagMap =
            {
            //"09...", "+959...","959...","random"
                    { "09...",  CountryCodeFlag::zero_nine},
                    { "+959...", CountryCodeFlag::plus_nine_five},
                    { "959...", CountryCodeFlag::nine_five},
                    { "Random", CountryCodeFlag::random}

            };

    static  phmap::flat_hash_map<std::string, Telecom > telecomMap =
            {
                    { "MPT",  Telecom::MPT},
                    { "Telenor", Telecom::Telenor},
                    { "Ooredoo", Telecom::Ooredoo},
                    { "MyTel", Telecom::Mytel},
                    { "Random", Telecom::Random}
            };

//Number

    enum class NumberSign{
        positive=1,negative=2,random=3
    };

    enum class NumberSystem{
        //rational look like random
                integer=1,fraction=2,rational=3
    };

    static  phmap::flat_hash_map<std::string, NumberSign > numSignMap =
            {
                    { "Positive",  NumberSign::positive},
                    { "Negative", NumberSign::negative},
                    { "Random", NumberSign::random}

            };

    static  phmap::flat_hash_map<std::string, NumberSystem > numSystemMap =
            {
                    { "Integer",  NumberSystem::integer},
                    { "Fraction", NumberSystem::fraction},
                    { "Random", NumberSystem::rational}

            };
    //NRC
    //"န","နိုင်"
    enum class NRCType {naing=1, ae=2,pyu=3, sa=4 , tha=5, thi=6, random=7};
    static  phmap::flat_hash_map<std::string, NRCType > nrcTypeMap =
            {
                    { "C",  NRCType::naing},
                    { "AC", NRCType::ae},
                    { "NC", NRCType::pyu},
                    { "V",  NRCType::sa},
                    { "M", NRCType::tha},
                    { "N", NRCType::thi},
                    { "Random", NRCType::random}

            };

};




#endif //XMWAYLOON_ENUMS_H
