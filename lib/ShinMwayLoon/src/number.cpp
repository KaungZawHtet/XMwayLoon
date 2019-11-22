//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#include "../include/number.h"
#include <string>
typedef Xlotgative::ShinMwayLoon::Number XMwayLoon_Number;
namespace XMwayLoon=Xlotgative::ShinMwayLoon;


std::string XMwayLoon_Number::convertEngNumToMyan(const std::string &engNum) {


    std::string result = "";

    std::for_each(engNum.begin(), engNum.end(), [this, &result](auto &engChar) {



      //  std::cout<<std::endl<< typeid(engChar).name()  <<std::endl;
        result+= this->convertSingleEngDigitToMyan(engChar);

       /* std::regex numRegex("[0-9]{1,2}");
        std::string str_Cache;
        str_Cache.push_back(engChar);


        if (std::regex_match(str_Cache, numRegex)) {
        auto iterator = this->myanNum->find(str_Cache);
        result += iterator->second;
    } else result +=str_Cache;
*/
    });


    return result;

}


std::string XMwayLoon_Number::getRandomMyanNum
( const unsigned long long min, const unsigned long long max,XMwayLoon_Number::Sign isMinus){

    boost::random::uniform_int_distribution<unsigned long long> myanNumDistribution(min, max);
    unsigned long long randomNum= myanNumDistribution(XMwayLoon::generatorObject);


    switch (isMinus)
    {
        case XMwayLoon_Number::Sign::Positive:
            return this->convertEngNumToMyan(std::to_string(randomNum));

        case XMwayLoon_Number::Sign::Negative:
            return "-"+this->convertEngNumToMyan(std::to_string(randomNum));
        default:
            if(randomNum%2)  return this->convertEngNumToMyan(std::to_string(randomNum));
            else  return "-"+this->convertEngNumToMyan(std::to_string(randomNum));

    }


   /* for(unsigned long i =0;i < max;i++)
    {
         cacheNum
        index = std::to_string(cacheNum);
        result += this->myanNum->find(index)->second;
    }*/


}

std::string XMwayLoon_Number::convertSingleEngDigitToMyan(char engNum)
{
    switch (engNum)
    {

        case '1': return "၁";
        case '2': return "၂";
        case '3': return "၃";
        case '4': return "၄";
        case '5': return "၅";
        case '6': return "၆";
        case '7': return "၇";
        case '8': return "၈";
        case '9': return "၉";
        default : return "၀";
    }

}

