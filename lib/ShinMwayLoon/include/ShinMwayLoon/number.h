//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#ifndef SHINMWAYLOON_NUMBER_H
#define SHINMWAYLOON_NUMBER_H
#include <map>
#include <random>


namespace Xlotgative::ShinMwayLoon
{
    class Number
    {
      //  typedef std::map<std::string, std::string> type_myanNum;
      //  std::string myanNum[10]{"၀","၁","၂","၃","၄","၅","၆","၇","၈","၉" } ;

    private:
        std::random_device objRandomDevice;
        void addFracNSignToNumberSequence();
        std::string myanNumSequence{};
        std::string engNumSequence{};
        std::string prefix{},postfix{};

    public:
        enum class Sign{
            Positive=1,Negative=2,Random=3
        };

        enum class System{
            Integer=1,Fraction=2,Random=3
        };
        
        Number();

        Sign isSigned;
        System isFraction;
        Number(Sign tempIsSigned,System tempIsFraction,std::string tempPrefix="",std::string tempPostfix="")
        : isSigned(std::move(tempIsSigned)) , isFraction(std::move(tempIsFraction)),
          prefix(std::move(tempPrefix)) , postfix(std::move(tempPostfix))
        {}

        std::string convertEngNumToMyan(const std::string &engNum);
        std::string getRandomMyanNum
        (  const unsigned long long min,const unsigned long long max);
        static std::string convertSingleEngDigitToMyan(char);


    };
}

#endif //SHINMWAYLOON_NUMBER_H
