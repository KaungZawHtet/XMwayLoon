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

    if(boolean==0) return this->num[0].data();
    else  return this->num[1].data();


}

std::string XMwayLoon_BooleanRandomizer::getBoolRandom
(const XML_RE::BoolType &type
        ,const XML_RE::Encoding encoding) {

    if(XML_RE::BoolType::num == type ) return this->getNumBool();
    else  return this->getAlphaBool(encoding); //(XMwayLoon_BooleanRandomizer::type::alpha==type)

}

std::string XMwayLoon_BooleanRandomizer::getAlphaBool(const XML_RE::Encoding &encoding) {
  //  pcg objPCG((std::random_device()));
    std::uniform_int_distribution<> booleanDistribution(0, 1);
    int boolean =booleanDistribution(this->objPCG) ;


    return [&]() {
    //    pcg objPCG((std::random_device()));
        switch (encoding) {
            case XML_RE::Encoding::unicode:

                return this->alpha[boolean].first.data()  ;
            case XML_RE::Encoding::zawgyi:
              return  this->alpha[boolean].second.data();
            default :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(this->objPCG)) {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                   return this->alpha[boolean].first.data();
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                  return  this->alpha[boolean].second.data();
                }
        }
    }();
}

/*XMwayLoon_BooleanRandomizer::BooleanRandomizer() {
   this->load();

}*/

std::string XMwayLoon_BooleanRandomizer::BooleanRandomizer::getRandom() {
   return this->getBoolRandom(this->objBoolType.type, this->objBoolType.encoding);
}


XMwayLoon_BooleanRandomizer::BooleanRandomizer(BooleanType tmp_objBoolType) :
objBoolType(std::move(tmp_objBoolType))
{
  this->load();
}


void XMwayLoon_BooleanRandomizer::load()
{
    std::random_device objRD;
    this->objPCG.seed( objRD);
}

