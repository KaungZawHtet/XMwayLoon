//
// Created by Kaung Zaw Htet on 2020-01-09.
//
#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/nrc_randomizer.h>
#include <model/type/enums.h>
#include <model/type/numeric_type.h>
#include <model/type/alphanumeric_type.h>
TEST(NRCTest,getNRC){

    NRCType objNRC;
    objNRC.type=XML_RE::NRCType::random;
    objNRC.encoding= XML_RE::Encoding ::random;
   
    XMwayLoon::Randomizer::NRCRandomizer objNRCRan(objNRC);
    for (int i = 0; i < 60; ++i) {
        std::string nrc= objNRCRan.getRandom( );
        std::cerr<<nrc<<std::endl;
        
    }
   
}
