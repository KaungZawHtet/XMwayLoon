//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#include <randomizer/nrc_randomizer.h>

#include <randomizer/typedef.h>

std::string XMwayLoon_NRCRandomizer::getNRC
(XMwayLoon_NRCRandomizer::Type type) {

    std::uniform_int_distribution<> typeDistribution(0, 1);
    int boolean =typeDistribution(this->objPCG) ;

    std::string idNum= this->objNumberRandomizer.getRandomMyanNum(100000,999999);

    std::string city;
    if(boolean) city =this->get2Alpha();
    else  city=this->get3Alpha();

    return [&](){

        switch (type)
        {
            case Type::n:
                return "၁၂/"+city+"("+ this->type[0]+ ")" +idNum;
                break;
            case Type::naing:
                return "၁၂/"+city+"("+ this->type[1]+ ")" +idNum;
                break;
            default:
            {
                int boolean =typeDistribution(this->objPCG) ;
                return "၁၂/"+city+"("+ this->type[boolean]+ ")" +idNum;
            }
                break;

        }


    }();




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