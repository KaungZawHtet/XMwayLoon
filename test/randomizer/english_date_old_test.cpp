//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/include/english_date_old.h>



TEST(EnglishDateTest,myanmarDateGeneration){

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    XMwayLoon::Randomizer::ptr_string ptr= obj_EnglishDate.getRandomMyanDate("%d-%B-%Y",XMwayLoon::Randomizer::Encoding::Random);


    std::cerr<< *ptr <<std::endl;
  //  EXPECT_TRUE(true);

}

TEST(EnglishDateTest,generateRandomEngDate){

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    XMwayLoon::Randomizer::ptr_string ptr= obj_EnglishDate.generateRandomEngDate("%d-%B-%Y");


    std::cerr<< *ptr <<std::endl;
    //  EXPECT_TRUE(true);

}

TEST(EnglishDateTest,convertShortEngMonthToMyan){

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    XMwayLoon::Randomizer::ptr_string ptr= obj_EnglishDate.convertShortEngMonthToMyan("Jan",XMwayLoon::Randomizer::Encoding::Random);
    std::cerr<< *ptr <<std::endl;

}
TEST(EnglishDateTest,convertCompleteEngMonthToMyan){

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    XMwayLoon::Randomizer::ptr_string ptr= obj_EnglishDate.convertCompleteEngMonthToMyan("January",XMwayLoon::Randomizer::Encoding::Random);
    std::cerr<< *ptr <<std::endl;

}

TEST(EnglishDateTest,create){

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    //  EXPECT_TRUE(true);

}
