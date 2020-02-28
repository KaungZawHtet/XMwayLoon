//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_NRC_RANDOMIZER_H
#define XMWAYLOON_NRC_RANDOMIZER_H
#include "faster_random.h"
#include <model/type/numeric_type.h>
#include <model/type/alphanumeric_type.h>
#include <randomizer/number_randomizer.h>
#include <string>
namespace XMwayLoon::Randomizer {

class NRCRandomizer : public RootRandomizer

        {


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



    NumberRandomizer objNumberRandomizer;
    NRCType objNRCType;
    std::string get3Alpha ();
    std::string get2Alpha ();
public:

    explicit NRCRandomizer(NRCType tmp_objNRCType);
    std::string getRandom() override ;
    void load() override ;
   // NRCRandomizer();
    std::string getNRC(XML_RE::NRCType type);
  





//ကခဂဃငစဆဈဇည ပဖဗဘမ ယရလဝသဟဏအ
    };
}


#endif //XMWAYLOON_NRC_RANDOMIZER_H
