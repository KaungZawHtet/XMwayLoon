//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#include <randomizer/ph_num/mytel.h>

std::string XMwayLoon::Randomizer::MyTel::getRandom() {


    std::string back= objNumRandomizer.getRandomMyanNum(1000000,9999999);

    return getPrefix()+ front +back;
}

XMwayLoon::Randomizer::MyTel::MyTel(XML_RE::CountryCodeFlag tmpCcFlag) : PhoneNumber(tmpCcFlag) {

}
