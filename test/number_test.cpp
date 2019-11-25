//
// Created by Kaung Zaw Htet on 2019-10-08.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../lib/ShinMwayLoon/include/ph_number.h"


typedef Xlotgative::ShinMwayLoon::Number XMwayLoon_Number;

TEST(NumberTest,convertEngNumToMyan){

    XMwayLoon_Number objNumber(XMwayLoon_Number::Sign::Negative ,XMwayLoon_Number::System::Fraction
            //,"Pre","MMK"
                               );
    std::string myanNum =objNumber.convertEngNumToMyan("645875423486");
    std::cerr<<myanNum<<std::endl;
}

TEST(NumberTest,getRandomMyanNum){
    Xlotgative::ShinMwayLoon::Number objNumber
    (XMwayLoon_Number::Sign::Random ,XMwayLoon_Number::System ::Fraction
            ,"F"
            );

    for (int i = 0; i < 100 ; ++i) {
        std::string myanNum =objNumber.getRandomMyanNum(4345364,78322424);
        std::cerr<<myanNum<<std::endl;
    }
    
}