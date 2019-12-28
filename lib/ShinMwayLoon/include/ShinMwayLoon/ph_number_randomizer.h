//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef SHINMWAYLOON_PH_NUMBER_H
#define SHINMWAYLOON_PH_NUMBER_H

#include <ShinMwayLoon/global_objects.h>
#include <map>
#include <array>
#include <boost/logic/tribool.hpp>
#include <ShinMwayLoon/number_randomizer.h>


namespace Xlotgative::ShinMwayLoon {

    class PhoneNumberRandomizer {

        typedef std::map<std::string, std::string> type_myanNum;


    private:
        std::array<std::pair<std::string, int>, 5> telenor
                {std::pair("75", 9), std::pair("76", 9), std::pair("77", 9),
                 std::pair("78", 9), std::pair("79", 9)};
        std::array<std::pair<std::string, int>, 3> ooredoo
                {std::pair("95", 9), std::pair("96", 9), std::pair("97", 9)};
        std::array<std::pair<std::string, int>, 1> mytel{std::pair("69", 9)};
        std::array<std::pair<std::string, int>, 10> mpt{std::pair("98", 9), std::pair("99", 9),
                                                             std::pair("76", 9), std::pair("76", 9),
                                                             std::pair("40", 9), std::pair("42", 9),
                                                             std::pair("44", 9), std::pair("45", 9),
                                                             std::pair("46", 9), std::pair("48", 9)};
        Xlotgative::ShinMwayLoon::NumberRandomizer objNumberRandomizer;
        std::random_device objRandomDevice;


    public:

        enum class CountryCodeFlag {
            withCountryCode, noCountryCode, random
        };
        enum class PhoneOperator {
            MPT, Telenor, Ooredoo, Mytel
        };
        std::string generateEngPhNum(const CountryCodeFlag countryCodeSwitch);
        std::string getRandomMyanPhNum(const CountryCodeFlag countryCodeSwitch);
    };
};

#endif //SHINMWAYLOON_PH_NUMBER_H
