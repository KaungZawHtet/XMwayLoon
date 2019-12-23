//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#include <ShinMwayLoon/number.h>
#include <string>
#include <ShinMwayLoon/faster_random.h>
typedef Xlotgative::ShinMwayLoon::Number XMwayLoon_Number;



std::string XMwayLoon_Number::convertEngNumToMyan(const std::string &engNum) {
    std::string result = "";
    this->engNumSequence=engNum;
    this->addFracNSignToNumberSequence();

    std::for_each(this->engNumSequence.begin(), this->engNumSequence.end(), [this, &result](auto &engChar) {
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

void XMwayLoon_Number::addFracNSignToNumberSequence()
{
    std::uniform_int_distribution<int> boolDistribution(0, 1);
    pcg objPCG(this->objRandomDevice);



    int length= this->engNumSequence.length();
    std::uniform_int_distribution<int> fractionDistribution(1, length-1);
    switch (this->isFraction)
    {
        case XMwayLoon_Number::System::Fraction:
            this->engNumSequence.insert(fractionDistribution(objPCG),".");
            break;

        case XMwayLoon_Number::System::Integer:
            break;
        default:
            if(boolDistribution(objPCG))
                this->engNumSequence.insert(fractionDistribution(objPCG),".");
    }

    switch (this->isSigned)
    {
        case XMwayLoon_Number::Sign::Positive:
            break;

        case XMwayLoon_Number::Sign::Negative:
            this->engNumSequence= "-"+this->engNumSequence;
            break;
        default:
            if(boolDistribution(objPCG))   this->engNumSequence= "-"+this->engNumSequence;

    }

}


std::string XMwayLoon_Number::getRandomMyanNum
( const unsigned long long min, const unsigned long long max){

    std::uniform_int_distribution<unsigned long long> myanNumDistribution(min, max);
    pcg objPCG(this->objRandomDevice);
    unsigned long long randomNum= myanNumDistribution(objPCG);

    this->myanNumSequence= this->convertEngNumToMyan(std::to_string(randomNum));

    return  this->prefix+this->myanNumSequence+this->postfix;




    /*switch (this->isSigned)
    {
        case XMwayLoon_Number::Sign::Positive:
            return this->convertEngNumToMyan(std::to_string(randomNum));

        case XMwayLoon_Number::Sign::Negative:
            return "-"+this->convertEngNumToMyan(std::to_string(randomNum));
        default:
            if(randomNum%2)  return this->convertEngNumToMyan(std::to_string(randomNum));
            else  return "-"+this->convertEngNumToMyan(std::to_string(randomNum));

    }*/


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
        case '0' : return "၀";
        default: return std::string{engNum};
    }

}

XMwayLoon_Number::Number(){
}




