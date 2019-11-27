//
// Created by Kaung Zaw Htet on 2019-11-22.
//


#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/pangram.h>

TEST(PangramTest,getPangram){

    Xlotgative::ShinMwayLoon::Pangram obj_Pangram;
    std::string myanNum =obj_Pangram.getPangram(Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cerr<<myanNum<<std::endl;
}