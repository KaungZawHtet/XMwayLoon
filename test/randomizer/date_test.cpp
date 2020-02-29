//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/date_randomizer.h>
#include <model/type/alphanumeric_type.h>


#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
using namespace std;
using namespace boost;
TEST(DateTest,convertCompleteEngMonthToMyan){

    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    std::string MyanMonth= objDateRandomizer.convertCompleteEngMonthToMyan("July",XML_RE::Encoding::random);
    std::cerr<<MyanMonth <<std::endl;
}


TEST(DateTest,convertShortEngMonthToMyan){

    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    std::string MyanMonth= objDateRandomizer.convertShortEngMonthToMyan("Jun",XML_RE::Encoding::random);
    std::cerr<<MyanMonth <<std::endl;
}

TEST(DateTest,generateRandomEngDate){

    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="YYYY-mmm-DD";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);

    for (int j = 0; j < 100; ++j) {
        std::string engDate= objDateRandomizer.generateRandomEngDate("%D-%B-%Y");
        std::cerr<<engDate <<std::endl;
    }


}

TEST(DateTest,convertEngDateToMyan){
    std::random_device gen;

    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::unicode;
    objDateType.format="%d-%b-%y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);

    for (int j = 0; j < 10; ++j) {
        std::string engDate= objDateRandomizer.generateRandomEngDate("%d-%b-%y");
        std::string MyanMonth= objDateRandomizer.convertEngDateToMyan(engDate,objDateType.encoding);
        std::cerr<<MyanMonth <<std::endl;
    }
    }



TEST(DateTest,create){


    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%b-%y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    //  EXPECT_TRUE(true);

}


TEST(DateTest,myanmarDateGeneration){


    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::random;
    objDateType.format="%d-%b-%y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    std::string myanDate= objDateRandomizer.getRandomMyanDate("%d-%B-%Y",XML_RE::Encoding::random);
    std::cerr<< myanDate <<std::endl;
    //  EXPECT_TRUE(true);

}
TEST(DateTest,getRandom){


    DateType objDateType;
    objDateType.encoding=XML_RE::Encoding::unicode;
    objDateType.format="%D-%B-%Y";


    XMwayLoon::Randomizer::DateRandomizer objDateRandomizer(objDateType);
    for (int j = 0; j < 10 ; ++j) {
        std::string myanDate= objDateRandomizer.getRandom();
        std::cerr<< myanDate <<std::endl;
    }


    //  EXPECT_TRUE(true);

}




TEST(DateTest,regexTest){




    std::string test = "12-Jan-13";
     test= boost::regex_replace(test, boost::regex(R"([A-Za-z]+)"), [](auto element){

        // std::string a= element ;
         std::cerr<< element <<"\n";
    return "ကိန်";

    });
    std::cerr<< test;



}
