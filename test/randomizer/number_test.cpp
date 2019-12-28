//
// Created by Kaung Zaw Htet on 2019-10-08.
//

#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/number_randomizer.h>



typedef Xlotgative::ShinMwayLoon::NumberRandomizer XMwayLoon_NumberRandomizer;

TEST(NumberTest,convertEngNumToMyan){

    XMwayLoon_NumberRandomizer objNumber(XMwayLoon_NumberRandomizer::Sign::Negative ,XMwayLoon_NumberRandomizer::System::Fraction
            //,"Pre","MMK"
                               );
    std::string myanNum =objNumber.convertEngNumToMyan("645875423486");
    std::cerr<<myanNum<<std::endl;
}

TEST(NumberTest,getRandomMyanNum){
    Xlotgative::ShinMwayLoon::NumberRandomizer objNumber
    (XMwayLoon_NumberRandomizer::Sign::Random ,XMwayLoon_NumberRandomizer::System ::Fraction
            ,"F"
            );

    for (int i = 0; i < 100 ; ++i) {
        std::string myanNum =objNumber.getRandomMyanNum(4345364,78322424);
        std::cerr<<myanNum<<std::endl;
    }
    
}