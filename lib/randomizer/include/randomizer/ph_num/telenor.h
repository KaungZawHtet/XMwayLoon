//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#ifndef XMWAYLOON_TELENOR_H
#define XMWAYLOON_TELENOR_H
#include "ph_number.h"

namespace XMwayLoon::Randomizer {
    class Telenor :virtual public XMwayLoon::Randomizer::PhoneNumber {

    private:
        static inline  std::array<std::string, 3> arrFront = {"၇၇", "၇၈", "၇၉"};

    public:
        Telenor(XML_RE::CountryCodeFlag tmpCcFlag);

        std::string getRandom() override ;

    };

}

#endif //XMWAYLOON_TELENOR_H
