//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#include <randomizer/number_randomizer.h>
#include <string>
#include <randomizer/faster_random.h>
#include <randomizer/typedef.h>


std::string XMwayLoon_NumberRandomizer::convertEngNumToMyan(const std::string &engNum) {
    std::string result = "";
    this->engNumSequence=engNum;
    this->addFracNSignToNumberSequence();

    std::for_each(this->engNumSequence.begin(), this->engNumSequence.end(), [this, &result](auto &engChar) {

        result+= this->convertSingleEngDigitToMyan(engChar);
    });

    return result;

}
//TODO: this can be fixed by gui option
void XMwayLoon_NumberRandomizer::addFracNSignToNumberSequence()
{
    std::uniform_int_distribution<int> boolDistribution(0, 1);


    int length= this->engNumSequence.length();
    std::uniform_int_distribution<int> fractionDistribution(1, length-1);
    switch (this->objNumType.system)
    {
        case XML_RE::NumberSystem::fraction:
            this->engNumSequence.insert(fractionDistribution(this->objPCG),".");
            break;

        case XML_RE::NumberSystem::integer:
            break;
        default:
            if(boolDistribution(this->objPCG))
                this->engNumSequence.insert(fractionDistribution(this->objPCG),".");
    }

    switch (this->objNumType.sign)
    {
        case XML_RE::NumberSign::positive:
            break;

        case XML_RE::NumberSign::negative:
            this->engNumSequence= "-"+this->engNumSequence;
            break;
        case XML_RE::NumberSign::random:
            if(boolDistribution(this->objPCG))   this->engNumSequence= "-"+this->engNumSequence;
            break;

    }

}

//TODO: This one too
std::string XMwayLoon_NumberRandomizer::getRandomMyanNum
( const unsigned long long min, const unsigned long long max){

    std::uniform_int_distribution<unsigned long long> myanNumDistribution(min, max);
    unsigned long long randomNum= myanNumDistribution(this->objPCG);

    this->myanNumSequence= this->convertEngNumToMyan(std::to_string(randomNum));

    return  this->objNumType.prefix+this->myanNumSequence+this->objNumType.postfix;


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

XMwayLoon_NumberRandomizer::NumberRandomizer(NumberType tmp_objNumType)
: objNumType(std::move(tmp_objNumType))

{
    this->load();
}

std::string XMwayLoon_NumberRandomizer::getRandom() {

//TODO: Total mistake
    return this->getRandomMyanNum(this->objNumType.min,this->objNumType.max);
}

void XMwayLoon_NumberRandomizer::load() {

    std::random_device objRD;
    this->objPCG.seed( objRD);
}


XMwayLoon_NumberRandomizer::NumberRandomizer(
        XML_RE::NumberSign tmp_isSigned,
XML_RE::NumberSystem tmp_isFraction, std::string tmp_prefix,
        std::string tmp_postfix, unsigned long long tmp_min , unsigned long long tmp_max)
{
    this->objNumType.sign=std::move(tmp_isSigned);
    this->objNumType.system=std::move(tmp_isFraction);
    this->objNumType.prefix=std::move(tmp_prefix);
    this->objNumType.postfix=std::move(tmp_postfix);
    this->objNumType.min=std::move(tmp_min);
    this->objNumType.max=std::move(tmp_max);
    this->load();
}






