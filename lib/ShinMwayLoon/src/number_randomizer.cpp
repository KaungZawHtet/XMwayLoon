//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#include <ShinMwayLoon/number_randomizer.h>
#include <string>
#include <ShinMwayLoon/faster_random.h>
#include <ShinMwayLoon/typedef.h>


std::string XMwayLoon_NumberRandomizer::convertEngNumToMyan(const std::string &engNum) {
    std::string result = "";
    this->engNumSequence=engNum;
    this->addFracNSignToNumberSequence();

    std::for_each(this->engNumSequence.begin(), this->engNumSequence.end(), [this, &result](auto &engChar) {

        result+= this->convertSingleEngDigitToMyan(engChar);
    });

    return result;

}

void XMwayLoon_NumberRandomizer::addFracNSignToNumberSequence()
{
    std::uniform_int_distribution<int> boolDistribution(0, 1);


    int length= this->engNumSequence.length();
    std::uniform_int_distribution<int> fractionDistribution(1, length-1);
    switch (this->isFraction)
    {
        case XMwayLoon_NumberRandomizer::System::fraction:
            this->engNumSequence.insert(fractionDistribution(this->objPCG),".");
            break;

        case XMwayLoon_NumberRandomizer::System::integer:
            break;
        default:
            if(boolDistribution(this->objPCG))
                this->engNumSequence.insert(fractionDistribution(this->objPCG),".");
    }

    switch (this->isSigned)
    {
        case XMwayLoon_NumberRandomizer::Sign::positive:
            break;

        case XMwayLoon_NumberRandomizer::Sign::negative:
            this->engNumSequence= "-"+this->engNumSequence;
            break;
        default:
            if(boolDistribution(this->objPCG))   this->engNumSequence= "-"+this->engNumSequence;

    }

}


std::string XMwayLoon_NumberRandomizer::getRandomMyanNum
( const unsigned long long min, const unsigned long long max){

    std::uniform_int_distribution<unsigned long long> myanNumDistribution(min, max);
    unsigned long long randomNum= myanNumDistribution(this->objPCG);

    this->myanNumSequence= this->convertEngNumToMyan(std::to_string(randomNum));

    return  this->prefix+this->myanNumSequence+this->postfix;


}

 std::string XMwayLoon_NumberRandomizer::convertSingleEngDigitToMyan(char engNum)
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

XMwayLoon_NumberRandomizer::NumberRandomizer(
        XMwayLoon_NumberRandomizer::Sign tempIsSigned,
XMwayLoon_NumberRandomizer ::System tempIsFraction, std::string tempPrefix,
        std::string tempPostfix) : isSigned(tempIsSigned) , isFraction(tempIsFraction),
                                   prefix(std::move(tempPrefix)) , postfix(std::move(tempPostfix))
{
    std::random_device objRD;
    this->objPCG.seed( objRD);
}






