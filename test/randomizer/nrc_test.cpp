//
// Created by Kaung Zaw Htet on 2020-01-09.
//
#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/nrc_randomizer.h>


TEST(NRCTest,getNRC){

   
    XMwayLoon::Randomizer::NRCRandomizer objNRCRan;
    for (int i = 0; i < 60; ++i) {
        std::string nrc= objNRCRan.getNRC( XMwayLoon::Randomizer::NRCRandomizer::Type::random);
        std::cerr<<nrc<<std::endl;
        
    }
   
}
