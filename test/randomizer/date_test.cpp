//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/date_randomizer.h>
#include <model/type/alphanumeric_type.h>

TEST(DateTest,convertCompleteEngMonthToMyan){

    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    std::string MyanMonth= objDateRandomizer.convertCompleteEngMonthToMyan("April",XML_RE::Encoding::random);
    std::cerr<<MyanMonth <<std::endl;
}


TEST(DateTest,convertShortEngMonthToMyan){

    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    std::string MyanMonth= objDateRandomizer.convertShortEngMonthToMyan("May",XML_RE::Encoding::random);
    std::cerr<<MyanMonth <<std::endl;
}

TEST(DateTest,generateRandomEngDate){

    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    std::string MyanMonth= objDateRandomizer.generateRandomEngDate("%d-%B-%Y");
    std::cerr<<MyanMonth <<std::endl;
}

TEST(DateTest,convertEngDateToMyan){
    std::random_device gen;

    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    std::string MyanMonth= objDateRandomizer.generateRandomEngDate("%d-%B-%Y");
    std::cerr<<MyanMonth <<std::endl;
}


TEST(DateTest,create){


    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    //  EXPECT_TRUE(true);

}


TEST(DateTest,myanmarDateGeneration){


    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    std::string myanDate= objDateRandomizer.getRandomMyanDate("%d-%B-%Y",XML_RE::Encoding::random);
    std::cerr<< myanDate <<std::endl;
    //  EXPECT_TRUE(true);

}
TEST(DateTest,getRandom){


    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::zawgyi;
    objDateType.format="%d-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    for (int j = 0; j < 10 ; ++j) {
        std::string myanDate= objDateRandomizer.getRandom();
        std::cerr<< myanDate <<std::endl;
    }


    //  EXPECT_TRUE(true);

}