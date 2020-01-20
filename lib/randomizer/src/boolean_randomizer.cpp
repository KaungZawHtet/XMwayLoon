//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#include <randomizer/boolean_randomizer.h>
#include <functional>

#include <randomizer/typedef.h>



std::string XMwayLoon_BooleanRandomizer::getNumBool (){
   // pcg objPCG((std::random_device()));
    std::uniform_int_distribution<> booleanDistribution(0, 1);
    int boolean = booleanDistribution(this->objPCG);

    if(boolean==0) return this->num[0];
    else  return this->num[1];


}

std::string XMwayLoon_BooleanRandomizer::getBooleanRandomizer
(const XMwayLoon_BooleanRandomizer::type &type
        ,const XMwayLoon::Randomizer::Encoding &encoding) {

    if(XMwayLoon_BooleanRandomizer::type::num==type ) return this->getNumBool();
    else  return this->getAlphaBool(encoding); //(XMwayLoon_BooleanRandomizer::type::alpha==type)

}

std::string XMwayLoon_BooleanRandomizer::getAlphaBool(const XMwayLoon::Randomizer::Encoding &encoding) {
  //  pcg objPCG((std::random_device()));
    std::uniform_int_distribution<> booleanDistribution(0, 1);
    int boolean =booleanDistribution(this->objPCG) ;


    return [&]() {
    //    pcg objPCG((std::random_device()));
        switch (encoding) {
            case XMwayLoon::Randomizer::Encoding::unicode:

                return this->alpha[boolean].first  ;
            case XMwayLoon::Randomizer::Encoding::zawgyi:
              return  this->alpha[boolean].second;
            default :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(this->objPCG)) {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                   return this->alpha[boolean].first;
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                  return  this->alpha[boolean].second;
                }
        }
    }();
}

XMwayLoon_BooleanRandomizer::BooleanRandomizer() {
    std::random_device objRD;
    this->objPCG.seed( objRD);

}



