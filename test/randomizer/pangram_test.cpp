//
// Created by Kaung Zaw Htet on 2019-11-22.
//


#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/pangram_randomizer.h>

TEST(PangramTest,getPangram){

    XMwayLoon::Randomizer::PangramRandomizer objPangramRandomizer;
    std::string myanNum =objPangramRandomizer.getPangram(XML_RE::Encoding::random);
    std::cerr<<myanNum<<std::endl;
}