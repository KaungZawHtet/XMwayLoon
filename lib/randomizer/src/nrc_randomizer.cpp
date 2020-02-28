//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#include <randomizer/nrc_randomizer.h>

#include <randomizer/typedef.h>

std::string XMwayLoon_NRCRandomizer::getNRC
(XML_RE::NRCType type) {

    std::uniform_int_distribution<> typeDistribution(0, 1);
    int boolean =typeDistribution(this->objPCG) ;

    std::string idNum= this->objNumberRandomizer.getRandomMyanNum(100000,999999);
    std::string stateCode =this->objNumberRandomizer.getRandomMyanNum(1,14);

    std::string city;
    if(boolean) city =this->get2Alpha();
    else  city=this->get3Alpha();

    return [&](){

        switch (type)
        {
            case XML_RE::NRCType::n:
                return stateCode+"/"+city+"("+ this->type[0]+ ")" +idNum;
                break;
            case XML_RE::NRCType::naing:
                return stateCode+"/"+city+"("+ this->type[1]+ ")" +idNum;
                break;
            default:
            {
                int boolean =typeDistribution(this->objPCG) ;
                return stateCode+"/"+city+"("+ this->type[boolean]+ ")" +idNum;
            }
                break;

        }


    }();




}

XMwayLoon_NRCRandomizer::NRCRandomizer(NRCType
tmp_objNRCType)
: objNRCType(std::move(tmp_objNRCType))
{
    this->load();
}


void XMwayLoon_NRCRandomizer::load()
{
    std::random_device objRD;
    this->objPCG.seed( objRD);
}
std::string XMwayLoon_NRCRandomizer::getRandom()
{
    return this->getNRC(objNRCType.type);
}

/*XMwayLoon_NRCRandomizer::NRCRandomizer() {
    this->load();

}*/

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
