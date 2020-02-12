//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#include <randomizer/ph_num/mpt.h>


std::string XMwayLoon::Randomizer::MPT::get1th() {

    return std::string("၅")+ objNumRandomizer.getRandomMyanNum(100000,999999); //
}

std::string XMwayLoon::Randomizer::MPT::get2nd() {
    return std::string("၄")+  objNumRandomizer.getRandomMyanNum(1000000,99999999);//7-8
}

std::string XMwayLoon::Randomizer::MPT::get3nd() {
    return std::string("၂")+  objNumRandomizer.getRandomMyanNum(100000,99999999); //6-8
}

std::string XMwayLoon::Randomizer::MPT::get4th() {
    return std::string("၃")+  objNumRandomizer.getRandomMyanNum(1000000,99999999); //7-8
}

std::string XMwayLoon::Randomizer::MPT::get5th() {
    return std::string("၆")+  objNumRandomizer.getRandomMyanNum(100000,999999); //6
}

std::string XMwayLoon::Randomizer::MPT::get6th() {
    return std::string("၈")+  objNumRandomizer.getRandomMyanNum(100000,999999); // 6
}

std::string XMwayLoon::Randomizer::MPT::get7th() {
    return std::string("၇")+  objNumRandomizer.getRandomMyanNum(1000000,9999999); //7
}

std::string XMwayLoon::Randomizer::MPT::get8th() {

    //0 1 9
    std::array<std::string,3> arrMiddle =  { "၀","၁","၉"};
    std::uniform_int_distribution<int> middleDistribution(0, 2);
    int index =middleDistribution(this->objPCG) ;

    return std::string("၉")
           + arrMiddle[index]
           + objNumRandomizer.getRandomMyanNum(10000,999999);
}

std::string XMwayLoon::Randomizer::MPT::getRandom() {

    std::uniform_int_distribution<int> middleDistribution(1, 8);
    int index =middleDistribution(this->objPCG) ;

    switch (index)
    {
        case 1:
            return this->getPrefix()+get1th();
        case 2:
            return this->getPrefix()+get2nd();
        case 3:
            return this->getPrefix()+get3nd();
        case 4:
            return this->getPrefix()+get4th();
        case 5:
            return this->getPrefix()+get5th();
        case 6:
            return this->getPrefix()+get6th();
        case 7:
            return this->getPrefix()+get7th();
        case 8:
            return this->getPrefix()+get8th();
    }



}

XMwayLoon::Randomizer::MPT::MPT(XML_RE::CountryCodeFlag tmpCcFlag) : PhoneNumber(tmpCcFlag) {

}
