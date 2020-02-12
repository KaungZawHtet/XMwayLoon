//
// Created by Kaung Zaw Htet on 2019-10-08.
//

#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/number_randomizer.h>
#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>


typedef XMwayLoon::Randomizer::NumberRandomizer XMwayLoon_NumRan;






TEST(NumberTest,convertEngNumToMyan){

    XMwayLoon_NumRan objNumber(XML_RE::NumberSign::negative , XML_RE::NumberSystem::fraction
            //,"Pre","MMK"
                               );
    std::string myanNum =objNumber.convertEngNumToMyan("645875423486");
    std::cerr<<myanNum<<std::endl;
}

TEST(NumberTest,getRandomMyanNum){
    XMwayLoon::Randomizer::NumberRandomizer objNumber
            (XML_RE::NumberSign::random , XML_RE::NumberSystem::rational, "MMK");

    for (int i = 0; i < 100 ; ++i) {
        std::string myanNum =objNumber.getRandomMyanNum(4345364,78322424);
        std::cerr<<myanNum<<std::endl;
    }
    
}

TEST(NumberTest,getRandom){
    NumberType data;
   data.prefix="";
    data.postfix="Kyat";
    data.setMin("100");
    data.setMax("101");
    data.setSystem("Integer");
   // data.setSign("Negative");

    XMwayLoon::Randomizer::NumberRandomizer objNumber
            (data);
    for (int i = 0; i < 100 ; ++i) {
        std::string myanNum =objNumber.getRandom();
        std::cerr<<myanNum<<std::endl;
    }




}