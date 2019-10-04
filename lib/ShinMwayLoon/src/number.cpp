//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#include "../include/number.h"
#include <regex>
#include <iostream>
#include "../include/global_objects.h"
typedef Xlotgative::ShinMwayLoon::Number XMwayLoon_Number;
namespace XMwayLoon=Xlotgative::ShinMwayLoon;
XMwayLoon_Number::Number() {
    this->myanNum = std::make_unique<type_myanNum>();


    this->myanNum->operator[]("0") = "၀";
    this->myanNum->operator[]("1") = "၁";
    this->myanNum->operator[]("2") = "၂";
    this->myanNum->operator[]("3") = "၃";
    this->myanNum->operator[]("4") = "၄";
    this->myanNum->operator[]("5") = "၅";
    this->myanNum->operator[]("6") = "၆";
    this->myanNum->operator[]("7") = "၇";
    this->myanNum->operator[]("8") = "၈";
    this->myanNum->operator[]("9") = "၉";


}

XMwayLoon::ptr_string XMwayLoon_Number::convertEngNumToMyan(const std::string &engNum) {


    std::string result = "";

    std::for_each(engNum.begin(), engNum.end(), [this, &result](auto &engChar) {


        std::regex numRegex("[0-9]{1,2}");
        std::string str_Cache;
        str_Cache.push_back(engChar);


        if (std::regex_match(str_Cache, numRegex)) {
        auto iterator = this->myanNum->find(str_Cache);
        result += iterator->second;
    } else result +=str_Cache;

    });


    return std::make_unique<std::string>(result);

}


XMwayLoon::ptr_string XMwayLoon_Number::generateMyanNum( const unsigned long max){

    boost::random::uniform_int_distribution<> myanNumDistribution(0, 9);
    std::string result="";
    int cacheNum;
    std::string index;

    for(unsigned long i =0;i < max;i++)
    {
         cacheNum = myanNumDistribution(XMwayLoon::generatorObject);
        index = std::to_string(cacheNum);
        result += this->myanNum->find(index)->second;
    }
    return std::make_unique<std::string>(result);

}


