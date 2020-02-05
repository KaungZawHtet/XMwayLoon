//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/date_randomizer.h>


TEST(DateTest,convertCompleteEngMonthToMyan){
    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer;
    std::string MyanMonth= objDateRandomizer.convertCompleteEngMonthToMyan("April",XML_RE::Encoding::random);
    std::cerr<<MyanMonth <<std::endl;
}


TEST(DateTest,convertShortEngMonthToMyan){
    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer;
    std::string MyanMonth= objDateRandomizer.convertShortEngMonthToMyan("May",XML_RE::Encoding::random);
    std::cerr<<MyanMonth <<std::endl;
}

TEST(DateTest,generateRandomEngDate){
    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer;
    std::string MyanMonth= objDateRandomizer.generateRandomEngDate("%d-%B-%Y");
    std::cerr<<MyanMonth <<std::endl;
}

TEST(DateTest,convertEngDateToMyan){
    std::random_device gen;
    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer;
    std::string MyanMonth= objDateRandomizer.generateRandomEngDate("%d-%B-%Y");
    std::cerr<<MyanMonth <<std::endl;
}


TEST(DateTest,create){

    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer;
    //  EXPECT_TRUE(true);

}


TEST(DateTest,myanmarDateGeneration){

    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer;
    std::string myanDate= objDateRandomizer.getRandomMyanDate("%d-%B-%Y",XML_RE::Encoding::random);
    std::cerr<< myanDate <<std::endl;
    //  EXPECT_TRUE(true);

}
