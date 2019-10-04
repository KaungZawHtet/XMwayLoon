//
// Created by Kaung Zaw Htet on 2019-10-04.
//

#include "../include/pangram.h"
#include <iostream>
#include "../include/global_objects.h"

typedef Xlotgative::ShinMwayLoon::Pangram XMwayLoon_Pangram;
namespace XMwayLoon =  Xlotgative::ShinMwayLoon;

XMwayLoon_Pangram::Pangram(){
    //first is alwasy unicode and second is zawgyi
    myanPangram.first="သီဟိုဠ်မှ ဉာဏ်ကြီးရှင်သည် အာယုဝဍ္ဎနဆေးညွှန်းစာကို ဇလွန်ဈေးဘေး ဗာဒံပင်ထက် အဓိဋ္ဌာန်လျက် ဂဃနဏဖတ်ခဲ့သည််။";
    myanPangram.second="သီဟိုဠ္မွ ဉာဏ္ႀကီးရွင္သည္ အာယုဝၯနေဆးၫႊန္းစာကို ဇလြန္ေဈးေဘး ဗာဒံပင္ထက္ အဓိ႒ာန္လ်က္ ဂဃနဏဖတ္ခဲ့သည္။";


}

XMwayLoon::ptr_string XMwayLoon_Pangram::getPangram(XMwayLoon::Encoding encoding){

    std::string result="";

    if(encoding==XMwayLoon::Encoding::Unicode){
        result= this->myanPangram.first;

    } else if(encoding==XMwayLoon::Encoding::Zawgyi){
        result= this->myanPangram.second;

    } else
    {
        boost::random::uniform_int_distribution<> encodingDistribution(1, 2);
        int encoding = encodingDistribution(generatorObject);
        if (encoding == 1) {
            result= this->myanPangram.first;
        } else {
             result= this->myanPangram.second;
        }
    }

    return std::make_unique<std::string>(result);


}