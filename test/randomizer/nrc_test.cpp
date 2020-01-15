//
// Created by Kaung Zaw Htet on 2020-01-09.
//
#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/nrc_randomizer.h>


TEST(NumberTest,getNRC){

   
    XMwayLoon::NRCRandomizer objNRCRan;
    for (int i = 0; i < 60; ++i) {
        std::string nrc= objNRCRan.getNRC(XMwayLoon::NRCRandomizer::Type::random);
        std::cerr<<nrc<<std::endl;
        
    }
   
}
