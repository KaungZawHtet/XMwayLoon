//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef SHINMWAYLOON_PH_NUMBER_H
#define SHINMWAYLOON_PH_NUMBER_H
#include "faster_random.h"
#include "root_randomizer.h"
#include <map>
#include <array>
#include <boost/logic/tribool.hpp>
#include <randomizer/number_randomizer.h>
#include <model/type/numeric_type.h>
#include <model/type/alphanumeric_type.h>

namespace XMwayLoon::Randomizer {

    class PhoneNumberRandomizer : public RootRandomizer {

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
        typedef XMwayLoon::Randomizer::NumberRandomizer XMwayLoon_NumRan;
        NumberRandomizer objNumberRandomizer;
        PhNumberType objPhNumberType;
         pcg objPCG;


    public:


        std::string generateEngPhNum(XML_RE::CountryCodeFlag countryCodeSwitch);
        std::string getRandomMyanPhNum(XML_RE::CountryCodeFlag countryCodeSwitch);
        PhoneNumberRandomizer();
        explicit PhoneNumberRandomizer(PhNumberType tmp_objPhNumberType);
        std::string getRandom () override ;
        void load() override ;

    };
};

#endif //SHINMWAYLOON_PH_NUMBER_H
