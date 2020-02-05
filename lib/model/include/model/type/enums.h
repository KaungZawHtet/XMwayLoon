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
    male = 1, female = 2, both = 3
};

 static  phmap::flat_hash_map<std::string, Gender > genderMap =
        {
                { "ကျား",  Gender::male},
                { "မ", Gender::female},
                { "ကျပန်း",  Gender::both}
        };

//For Bool Randomizer


enum class BoolType{num=1,alpha=2};
static  phmap::flat_hash_map<std::string, BoolType > boolTypeMap =
        {
                { "မှား/မှန်",  BoolType::alpha},
                { "၀/၁", BoolType::num},

        };


//


};




#endif //XMWAYLOON_ENUMS_H
