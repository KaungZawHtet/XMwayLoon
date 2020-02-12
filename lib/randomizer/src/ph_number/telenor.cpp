//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#include <randomizer/ph_num/telenor.h>

std::string XMwayLoon::Randomizer::Telenor::getRandom() {
    std::string back= objNumRandomizer.getRandomMyanNum(1000000,9999999);

    std::uniform_int_distribution<int> flagDistribution(0, 2);
    int index =flagDistribution(this->objPCG) ;


    return getPrefix()+ arrFront[index] +back;
}

XMwayLoon::Randomizer::Telenor::Telenor(XML_RE::CountryCodeFlag tmpCcFlag) : PhoneNumber(tmpCcFlag) {

}
