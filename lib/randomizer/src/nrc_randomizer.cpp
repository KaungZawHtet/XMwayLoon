//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#include <randomizer/nrc_randomizer.h>

#include <randomizer/typedef.h>

std::string XMwayLoon_NRCRandomizer::getNRC
(XML_RE::NRCType type) {

    std::uniform_int_distribution<> typeDistribution(0, 5);
    std::uniform_int_distribution<> boolDistribution(0, 1);
    int boolSD =boolDistribution(this->objPCG) ;

    std::string idNum= this->objNumberRandomizer.getRandomMyanNum(100000,999999);
    std::string stateCode =this->objNumberRandomizer.getRandomMyanNum(1,14);

    std::string city;
    if(boolSD) city =this->get2Alpha();
    else  city=this->get3Alpha();

    return [&](){
        std::string *tmp;
        int boolEncoding =boolDistribution(this->objPCG) ;

        switch (this->objNRCType.encoding)
        {
            case XML_RE::Encoding::unicode :
                tmp= this->uniTypes;
                break;
            case XML_RE::Encoding::zawgyi :
                tmp= this->zgTypes;
                break;
            case XML_RE::Encoding::random :
                if(boolEncoding) tmp= this->uniTypes;
                else  tmp= this->zgTypes;
                break;


        }



        switch (type)
        {
            case XML_RE::NRCType::naing:
                return stateCode+"/"+city+"("+ tmp[0]+ ")" +idNum;
                break;
            case XML_RE::NRCType::ae:
                return stateCode+"/"+city+"("+ tmp[1]+ ")" +idNum;
                break;
            case XML_RE::NRCType::pyu:
                return stateCode+"/"+city+"("+ tmp[2]+ ")" +idNum;
                break;
            case XML_RE::NRCType::sa:
                return stateCode+"/"+city+"("+ tmp[3]+ ")" +idNum;
                break;
            case XML_RE::NRCType::tha:
                return stateCode+"/"+city+"("+ tmp[4]+ ")" +idNum;
                break;
            case XML_RE::NRCType::thi:
                return stateCode+"/"+city+"("+ tmp[5]+ ")" +idNum;
                break;
            default:
            {
                int indexType = typeDistribution(this->objPCG);
                return stateCode+"/"+city+"("+ tmp[indexType]+ ")" +idNum;
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
