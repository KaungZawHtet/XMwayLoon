//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/date_randomizer.h>


TEST(DateTest,convertCompleteEngMonthToMyan){
    Xlotgative::ShinMwayLoon::DateRandomizer objDateRandomizer;
    std::string MyanMonth= objDateRandomizer.convertCompleteEngMonthToMyan("April",Xlotgative::ShinMwayLoon::Encoding::random);
    std::cerr<<MyanMonth <<std::endl;
}


TEST(DateTest,convertShortEngMonthToMyan){
    Xlotgative::ShinMwayLoon::DateRandomizer objDateRandomizer;
    std::string MyanMonth= objDateRandomizer.convertShortEngMonthToMyan("May",Xlotgative::ShinMwayLoon::Encoding::random);
    std::cerr<<MyanMonth <<std::endl;
}

TEST(DateTest,generateRandomEngDate){
    Xlotgative::ShinMwayLoon::DateRandomizer objDateRandomizer;
    std::string MyanMonth= objDateRandomizer.generateRandomEngDate("%d-%B-%Y");
    std::cerr<<MyanMonth <<std::endl;
}

TEST(DateTest,convertEngDateToMyan){
    std::random_device gen;
    Xlotgative::ShinMwayLoon::DateRandomizer objDateRandomizer;
    std::string MyanMonth= objDateRandomizer.generateRandomEngDate("%d-%B-%Y");
    std::cerr<<MyanMonth <<std::endl;
}


TEST(DateTest,create){

    Xlotgative::ShinMwayLoon::DateRandomizer objDateRandomizer;
    //  EXPECT_TRUE(true);

}


TEST(DateTest,myanmarDateGeneration){

    Xlotgative::ShinMwayLoon::DateRandomizer objDateRandomizer;
    std::string myanDate= objDateRandomizer.getRandomMyanDate("%d-%B-%Y",Xlotgative::ShinMwayLoon::Encoding::random);
    std::cerr<< myanDate <<std::endl;
    //  EXPECT_TRUE(true);

}
