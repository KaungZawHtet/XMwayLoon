//
// Created by Kaung Zaw Htet on 2019-10-08.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../lib/ShinMwayLoon/include/ph_number.h"


TEST(NumberTest,convertEngNumToMyan){

    Xlotgative::ShinMwayLoon::Number obj_Number;
    std::string myanNum =obj_Number.convertEngNumToMyan("645875423486");
    std::cerr<<myanNum<<std::endl;
}

TEST(NumberTest,getRandomMyanNum){
    Xlotgative::ShinMwayLoon::Number obj_Number;
    std::string myanNum =obj_Number.getRandomMyanNum(4345364,78322424,Xlotgative::ShinMwayLoon::Number::Sign::Random);
    std::cerr<<myanNum<<std::endl;

}