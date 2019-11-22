//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#ifndef SHINMWAYLOON_NUMBER_H
#define SHINMWAYLOON_NUMBER_H
#include <map>
#include "../include/global_objects.h"


namespace Xlotgative::ShinMwayLoon
{
    class Number
    {
      //  typedef std::map<std::string, std::string> type_myanNum;
      //  std::string myanNum[10]{"၀","၁","၂","၃","၄","၅","၆","၇","၈","၉" } ;


    public:
        enum class Sign{
            Positive=1,Negative=2,Random=3
        };

        std::string convertEngNumToMyan(const std::string &engNum);
        std::string getRandomMyanNum
        (  const unsigned long long min,const unsigned long long max,Sign isMinus);
        std::string convertSingleEngDigitToMyan(char);

    };
}

#endif //SHINMWAYLOON_NUMBER_H
