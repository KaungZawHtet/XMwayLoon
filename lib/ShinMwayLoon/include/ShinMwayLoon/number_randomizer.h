//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#ifndef SHINMWAYLOON_NUMBER_H
#define SHINMWAYLOON_NUMBER_H
#include <map>
#include <random>
#include "global_objects.h"

namespace Xlotgative::ShinMwayLoon
{
    class NumberRandomizer
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
        enum class Sign{
            positive=1,negative=2,random=3
        };

        enum class System{
            integer=1,fraction=2,rational=3
        };



        Sign isSigned;
        System isFraction;
        NumberRandomizer(Sign tempIsSigned=Sign::positive,System tempIsFraction=System::integer,std::string tempPrefix="",std::string tempPostfix="");


        std::string convertEngNumToMyan(const std::string &engNum);
        std::string getRandomMyanNum
        (  unsigned long long min,unsigned long long max);
        static std::string convertSingleEngDigitToMyan(char);


    };
}

#endif //SHINMWAYLOON_NUMBER_H
