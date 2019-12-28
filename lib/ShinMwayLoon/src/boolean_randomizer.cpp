//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#include <ShinMwayLoon/global_objects.h>
#include <ShinMwayLoon/boolean_randomizer.h>
#include <utility>
#include <functional>

typedef Xlotgative::ShinMwayLoon::BooleanRandomizer XMwayLoon_BooleanRandomizer;


std::string XMwayLoon_BooleanRandomizer::getNumBool (){
    pcg objPCG(this->objRandomDevice);
    std::uniform_int_distribution<> booleanDistribution(0, 1);
    int boolean = booleanDistribution(objPCG);

    if(boolean==0) return this->num[0];
    else  return this->num[1];


}

std::string XMwayLoon_BooleanRandomizer::getBooleanRandomizer
(const XMwayLoon_BooleanRandomizer::type &type
        ,const XMwayLoon::Encoding &encoding) {

    if(XMwayLoon_BooleanRandomizer::type::num==type ) return this->getNumBool();
    if (XMwayLoon_BooleanRandomizer::type::alpha==type) return this->getAlphaBool(encoding);

}

std::string XMwayLoon_BooleanRandomizer::getAlphaBool(const XMwayLoon::Encoding &encoding) {
    pcg objPCG(this->objRandomDevice);
    std::uniform_int_distribution<> booleanDistribution(0, 1);
    int boolean =booleanDistribution(objPCG) ;


    return [&]() {
        pcg objPCG(this->objRandomDevice);
        switch (encoding) {
            case XMwayLoon::Encoding::Unicode:

                return this->alpha[boolean].first  ;
            case XMwayLoon::Encoding::Zawgyi:
              return  this->alpha[boolean].second;
            default :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(objPCG)) {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                   return this->alpha[boolean].first;
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                  return  this->alpha[boolean].second;
                }
        }
    }();
}


