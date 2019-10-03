//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef FAKEDATAGENERATOR_PH_NUMBER_H
#define FAKEDATAGENERATOR_PH_NUMBER_H

#include "../include/global_objects.h"
#include <map>
#include <array>
#include <boost/logic/tribool.hpp>
#include "../include/number.h"


namespace Xlotgative
{

    class PhoneNumber
    {

        typedef std::map<std::string, std::string> type_myanNum;
        typedef std::array<std::pair<std::string,int>,5> type_telenor;
        typedef std::array<std::pair<std::string,int>,3> type_ooredoo;
        typedef std::array<std::pair<std::string,int>,1> type_mytel;
        typedef std::array<std::pair<std::string,int>,10> type_mpt;

        //prefix and length. In prefix, 09 is not included
        std::unique_ptr<type_mpt> mpt;



        std::unique_ptr<type_telenor> telenor;
        std::unique_ptr<type_ooredoo> ooredoo;
        std::unique_ptr<type_mytel> mytel;

        Xlotgative::Number obj_number;



    public:

        enum class CountryCodeFlag{withCountryCode,noCountryCode,random};
        enum class PhoneOperator{MPT,Telenor,Ooredoo,Mytel};

        PhoneNumber();


        ptr_string generateEngPhNum(const CountryCodeFlag countryCodeSwitch);
       ptr_string getRandomMyanPhNum(const CountryCodeFlag countryCodeSwitch);


    };


};



#endif //FAKEDATAGENERATOR_PH_NUMBER_H
