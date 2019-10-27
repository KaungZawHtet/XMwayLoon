//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../lib/ShinMwayLoon/include/english_date.h"



TEST(EnglishDateTest,myanmarDateGeneration){

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.getRandomMyanDate("%d-%B-%Y",Xlotgative::ShinMwayLoon::Encoding::Random);


    std::cerr<< *ptr <<std::endl;
  //  EXPECT_TRUE(true);

}

TEST(EnglishDateTest,generateRandomEngDate){

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.generateRandomEngDate("%d-%B-%Y");


    std::cerr<< *ptr <<std::endl;
    //  EXPECT_TRUE(true);

}
