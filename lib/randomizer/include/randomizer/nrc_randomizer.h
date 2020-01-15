//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_NRC_RANDOMIZER_H
#define XMWAYLOON_NRC_RANDOMIZER_H

#include <randomizer/global_objects.h>
#include <randomizer/number_randomizer.h>
#include <string>
namespace XMwayLoon::Randomizer {

class NRCRandomizer{


private:
std::string type[2]= {"န","နိုင်"};
std::string alphabet[25]
= {"က","ခ","ဂ","ဃ","င"
   ,"စ","ဆ","ဇ"
   ,"တ","ထ","ဒ","ဓ","န"
   ,"ပ","ဖ","ဗ","ဘ","မ"
   ,"ယ","ရ","လ","ဝ","သ"
   ,"ဟ","အ"
};

    pcg objPCG;
    NumberRandomizer objNumberRandomizer;
    std::string get3Alpha ();
    std::string get2Alpha ();
public:
    enum class Type { n=1,naing=2,random=3};
    NRCRandomizer();
    std::string getNRC(NRCRandomizer::Type type);
  





//ကခဂဃငစဆဈဇည ပဖဗဘမ ယရလဝသဟဏအ
    };
}


#endif //XMWAYLOON_NRC_RANDOMIZER_H
