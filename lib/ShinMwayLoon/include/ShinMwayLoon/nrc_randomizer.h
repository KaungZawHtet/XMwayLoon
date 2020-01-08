//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_NRC_RANDOMIZER_H
#define XMWAYLOON_NRC_RANDOMIZER_H

#include <ShinMwayLoon/global_objects.h>
#include <ShinMwayLoon/number_randomizer.h>
#include <string>
namespace Xlotgative::ShinMwayLoon {

class NRCRandomizer{


std::string type[2]= {"န","နိုင်"};
std::string alphabet[25]
= {"က","ခ","ဂ","ဃ","င"
   ,"စ","ဆ","ဇ"
   ,"တ","ထ","ဒ","ဓ","န"
   ,"ပ","ဖ","ဗ","ဘ","မ"
   ,"ယ","ရ","လ","ဝ","သ"
   ,"ဟ","အ"
};
enum class Type { N=1,Naing=2};
    pcg objPCG;
    NumberRandomizer objNumberRandomizer;

public:
    NRCRandomizer();
    std::string getNRC(NRCRandomizer::Type type);
    std::string get3Alpha ();
    std::string get2Alpha ();




//ကခဂဃငစဆဈဇည ပဖဗဘမ ယရလဝသဟဏအ
    };
}


#endif //XMWAYLOON_NRC_RANDOMIZER_H
