//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#ifndef XMWAYLOON_MPT_H
#define XMWAYLOON_MPT_H

#include "ph_number.h"
namespace XMwayLoon::Randomizer {
    class MPT : virtual public XMwayLoon::Randomizer::PhoneNumber {


    private:

        static inline std::array<std::string, 2> arrFront = {"၉၇", "၉၆"};


        std::string get1th();

        std::string get2nd();

        std::string get3nd();

        std::string get4th();

        std::string get5th();

        std::string get6th();

        std::string get7th();

        std::string get8th();

    public:
        MPT(XML_RE::CountryCodeFlag tmpCcFlag);
        std::string getRandom() override ;


    };
}

#endif //XMWAYLOON_MPT_H
