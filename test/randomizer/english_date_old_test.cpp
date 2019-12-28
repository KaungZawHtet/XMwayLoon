//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/include/english_date_old.h>



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

TEST(EnglishDateTest,convertShortEngMonthToMyan){

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.convertShortEngMonthToMyan("Jan",Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cerr<< *ptr <<std::endl;

}
TEST(EnglishDateTest,convertCompleteEngMonthToMyan){

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.convertCompleteEngMonthToMyan("January",Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cerr<< *ptr <<std::endl;

}

TEST(EnglishDateTest,create){

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    //  EXPECT_TRUE(true);

}
