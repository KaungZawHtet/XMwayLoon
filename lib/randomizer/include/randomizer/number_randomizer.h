//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#ifndef SHINMWAYLOON_NUMBER_H
#define SHINMWAYLOON_NUMBER_H
#include <map>
#include <random>
#include "faster_random.h"
#include "root_randomizer.h"
#include <model/type/enums.h>
#include <model/type/numeric_type.h>
#include <model/type/alphanumeric_type.h>
namespace XMwayLoon::Randomizer
{
    class NumberRandomizer : public RootRandomizer
    {
      //  typedef std::map<std::string, std::string> type_myanNum;
      //  std::string myanNum[10]{"၀","၁","၂","၃","၄","၅","၆","၇","၈","၉" } ;

    private:

        void addFracNSignToNumberSequence();
        std::string myanNumSequence{};
        std::string engNumSequence{};



    public:


       // XML_RE::NumberSign isSigned;
      //  XML_RE::NumberSystem isFraction;

        NumberType objNumType;
       //Number Randomizer is only one that needs customized constucture like this
        explicit NumberRandomizer(XML_RE::NumberSign tmp_isSigned=XML_RE::NumberSign::positive
                , XML_RE::NumberSystem tmp_isFraction=XML_RE::NumberSystem::integer, std::string tmp_prefix=""
                        , std::string tmp_postfix="", unsigned long long tmp_min=0, unsigned long long tmp_max=0);

        explicit NumberRandomizer(NumberType tmp_objNumType);
        std::string getRandom() override;
        void load() override;

        std::string convertEngNumToMyan(const std::string &engNum);
        std::string getRandomMyanNum
        (  unsigned long long min,unsigned long long max);
        static std::string convertSingleEngDigitToMyan(char);


    };
}

#endif //SHINMWAYLOON_NUMBER_H
