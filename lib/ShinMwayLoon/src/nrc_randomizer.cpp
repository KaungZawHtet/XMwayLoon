//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#include <ShinMwayLoon/nrc_randomizer.h>

#include <ShinMwayLoon/typedef.h>

std::string XMwayLoon_NRCRandomizer::getNRC
(XMwayLoon_NRCRandomizer::Type type) {

    std::uniform_int_distribution<> typeDistribution(1, 2);
    int boolean =typeDistribution(this->objPCG) ;





}

XMwayLoon_NRCRandomizer::NRCRandomizer() {
    std::random_device objRD;
    this->objPCG.seed( objRD);

}

std::string XMwayLoon_NRCRandomizer::get3Alpha() {
    std::uniform_int_distribution<> alphabetDistribution(0, 24);
    std::string result="";

    for (int i=0; i<3;i++)
    {
        int place =alphabetDistribution(this->objPCG) ;
        result+= this->alphabet[place];

    }
    return result;
}

std::string XMwayLoon_NRCRandomizer::get2Alpha() {
    std::uniform_int_distribution<> alphabetDistribution(0, 24);
    std::string result="";

    for (int i=0; i<2;i++)
    {
        int place =alphabetDistribution(this->objPCG) ;
        result+= this->alphabet[place];

    }
    return result;

}
