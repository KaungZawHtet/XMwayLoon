//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#include <randomizer/ph_num/ooredoo.h>

std::string XMwayLoon::Randomizer::Ooredoo::getRandom() {
    std::string back= objNumRandomizer.getRandomMyanNum(1000000,9999999);

    std::uniform_int_distribution<int> flagDistribution(0, 1);
    int index =flagDistribution(this->objPCG) ;


    return getPrefix()+ arrFront[index] +back;
}

XMwayLoon::Randomizer::Ooredoo::Ooredoo(XML_RE::CountryCodeFlag tmpCcFlag) : PhoneNumber(tmpCcFlag) {

}
