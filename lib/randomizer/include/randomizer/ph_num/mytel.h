//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#ifndef XMWAYLOON_MYTEL_H
#define XMWAYLOON_MYTEL_H
#include "ph_number.h"
namespace XMwayLoon::Randomizer {
    class MyTel :virtual public XMwayLoon::Randomizer::PhoneNumber {
        static inline std::string front = "၆၉";

    public:
        MyTel(XML_RE::CountryCodeFlag tmpCcFlag);
        std::string getRandom() override ;

    };
}
#endif //XMWAYLOON_MYTEL_H
