//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#ifndef XMWAYLOON_OOREDOO_H
#define XMWAYLOON_OOREDOO_H
#include "ph_number.h"

namespace XMwayLoon::Randomizer {
    class Ooredoo : virtual public XMwayLoon::Randomizer::PhoneNumber {

        static inline std::array<std::string, 2> arrFront = {"၉၇", "၉၆"};

    public:
        Ooredoo(XML_RE::CountryCodeFlag tmpCcFlag);
        std::string getRandom() override ;


    };

}

#endif //XMWAYLOON_OOREDOO_H
