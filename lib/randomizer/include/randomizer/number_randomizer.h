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
        std::string prefix{},postfix{};
        pcg objPCG;

    public:


        XML_RE::NumberSign isSigned;
        XML_RE::NumberSystem isFraction;

        NumberType objNumType;
        explicit NumberRandomizer(XML_RE::NumberSign tempIsSigned=XML_RE::NumberSign::positive
                ,XML_RE::NumberSystem tempIsFraction=XML_RE::NumberSystem::integer,std::string tempPrefix=""
                        ,std::string tempPostfix="");

        NumberRandomizer(NumberType tmp_objNumType);
        std::string getRandom() override;
        void load() override;

        std::string convertEngNumToMyan(const std::string &engNum);
        std::string getRandomMyanNum
        (  unsigned long long min,unsigned long long max);
        static std::string convertSingleEngDigitToMyan(char);


    };
}

#endif //SHINMWAYLOON_NUMBER_H
