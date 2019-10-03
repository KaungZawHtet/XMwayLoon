//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#include "../include/ph_number.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <regex>



typedef Xlotgative::PhoneNumber X_PhoneNumber;
X_PhoneNumber::PhoneNumber() {


    this->telenor = std::make_unique<type_telenor>(
            type_telenor{std::pair("75", 9), std::pair("76", 9), std::pair("77", 9), std::pair("78", 9),
                         std::pair("79", 9)});
    this->ooredoo = std::make_unique<type_ooredoo>(type_ooredoo{std::pair("95", 9), std::pair("96", 9), std::pair("97", 9)});
    this->mytel = std::make_unique<type_mytel>(type_mytel{std::pair("69", 9)});
    this->mpt = std::make_unique<type_mpt>(type_mpt{std::pair("98", 9), std::pair("99", 9),
                                               std::pair("76", 9), std::pair("76", 9),
                                               std::pair("40", 9), std::pair("42", 9),
                                               std::pair("44", 9), std::pair("45", 9),
                                               std::pair("46", 9), std::pair("48", 9)});


}


Xlotgative::ptr_string X_PhoneNumber::generateEngPhNum(CountryCodeFlag countryCodeSwitch) {
    boost::random::uniform_int_distribution<> operatorDistribution(1, 4);
    boost::random::uniform_int_distribution<> numberDistribution(0, 9);

    boost::random::uniform_int_distribution<> telenorPrefixDistribution(0, 4);
    boost::random::uniform_int_distribution<> ooredooPrefixDistribution(0, 2);
    boost::random::uniform_int_distribution<> MPTPrefixDistribution(0, 9);


    std::string result = "";
    int cacheNum;
    std::string str_cache;


    for (int i = 0; i < 7; i++) {

        cacheNum = numberDistribution(generatorObject);
        str_cache = std::to_string(cacheNum);
        result += str_cache;


        switch (operatorDistribution(generatorObject)) {

            case 1: //MPT

                result = "09" + this->mpt->operator[](MPTPrefixDistribution(generatorObject)).first + result;
                break;

            case 2: //Telenor

                result = "09" + this->telenor->operator[](telenorPrefixDistribution(generatorObject)).first + result;
                break;


            case 3: //Ooredoo

                result = "09" + this->ooredoo->operator[](ooredooPrefixDistribution(generatorObject)).first + result;
                break;

            case 4: //Mytel

                result = "09" + this->mytel->operator[](0).first + result;
                break;
        }


        switch (countryCodeSwitch) {
            case PhoneNumber::CountryCodeFlag::withCountryCode :
                result = "+95" + result;
                // std::cout<<endl<<result<<endl;

                break;
            case PhoneNumber::CountryCodeFlag::noCountryCode :
                break;
            case PhoneNumber::CountryCodeFlag::random :
                boost::random::uniform_int_distribution<> encodingDistribution(1, 2);
                int innerCountryCodeSwitch = encodingDistribution(generatorObject);
                if (innerCountryCodeSwitch == 1) result = "+95" + result;
                break;


        }


        return std::make_unique<std::string>(result);

    }
}


Xlotgative::ptr_string X_PhoneNumber::getRandomMyanPhNum(const PhoneNumber::CountryCodeFlag countryCodeSwitch) {


    Xlotgative::ptr_string result = PhoneNumber::generateEngPhNum(countryCodeSwitch);

    result = this->obj_number.convertEngNumToMyan(*result);

    return result;


}
