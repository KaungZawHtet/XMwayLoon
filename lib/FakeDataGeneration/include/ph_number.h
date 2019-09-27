//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef FAKEDATAGENERATOR_PH_NUMBER_H
#define FAKEDATAGENERATOR_PH_NUMBER_H

#include "../include/global_objects.h"
#include <map>
#include <array>

using namespace std;
namespace Xlotgative
{

    class PhoneNumber
    {

        //prefix and length. In prefix, 09 is not included
        array<pair<string,int>,10> mpt{pair("98",9),pair("99",9),pair("76",9),pair("76",9),pair("40",9),pair("42",9),pair("44",9),pair("45",9),pair("46",9),pair("48",9)};




        array<pair<string,int>,5> telenor{pair("75",9),pair("76",9),pair("77",9),pair("78",9),pair("79",9)};
        array<pair<string,int>,3> ooredoo{pair("95",9),pair("96",9),pair("97",9)  };
        array<pair<string,int>,1> mytel{pair("69",9)};


        std::map<std::string, pair <string,string>> myanmarNumberKeywords;
    public:
        PhoneNumber();
        void convertEnglishNumberToMyanmar(std::string &,string&);
        string generatePhoneNumber(string&);


    };


};



#endif //FAKEDATAGENERATOR_PH_NUMBER_H
