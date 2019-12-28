//
// Created by Kaung Zaw Htet on 2019-11-22.
//


#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/pangram_randomizer.h>

TEST(PangramTest,getPangram){

    Xlotgative::ShinMwayLoon::PangramRandomizer objPangramRandomizer;
    std::string myanNum =objPangramRandomizer.getPangram(Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cerr<<myanNum<<std::endl;
}