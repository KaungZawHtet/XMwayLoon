//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../lib/ShinMwayLoon/include/date.h"



TEST(DateTest,convertCompleteEngMonthToMyan){
    Xlotgative::ShinMwayLoon::Date obj_Date;
    std::string MyanMonth= obj_Date.convertCompleteEngMonthToMyan("April",Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cerr<<MyanMonth <<std::endl;
}


TEST(DateTest,convertShortEngMonthToMyan){
    Xlotgative::ShinMwayLoon::Date obj_Date;
    std::string MyanMonth= obj_Date.convertShortEngMonthToMyan("May",Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cerr<<MyanMonth <<std::endl;
}

TEST(DateTest,generateRandomEngDate){
    Xlotgative::ShinMwayLoon::Date obj_Date;
    std::string MyanMonth= obj_Date.generateRandomEngDate("%d-%B-%Y");
    std::cerr<<MyanMonth <<std::endl;
}

TEST(DateTest,convertEngDateToMyan){
    std::random_device gen;
    Xlotgative::ShinMwayLoon::Date obj_Date;
    std::string MyanMonth= obj_Date.generateRandomEngDate("%d-%B-%Y");
    std::cerr<<MyanMonth <<std::endl;
}


TEST(DateTest,create){

    Xlotgative::ShinMwayLoon::Date obj_Date;
    //  EXPECT_TRUE(true);

}


TEST(DateTest,myanmarDateGeneration){

    Xlotgative::ShinMwayLoon::Date obj_Date;
    std::string myanDate= obj_Date.getRandomMyanDate("%d-%B-%Y",Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cerr<< myanDate <<std::endl;
    //  EXPECT_TRUE(true);

}
