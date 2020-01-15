//
// Created by Kaung Zaw Htet on 2019-10-08.
//

#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/ph_number_randomizer.h>

TEST(PhoneNumberTest,getRandomMyanPhNum){
    XMwayLoon::Randomizer::PhoneNumberRandomizer objPhNumRD;
    for(int i=0;i<10;i++)
    {
        std::string ss=objPhNumRD.getRandomMyanPhNum(XMwayLoon::Randomizer::PhoneNumberRandomizer::CountryCodeFlag::random);
        std::cerr<<ss<<std::endl;

    }

}
TEST(PhoneNumberTest,generateEngPhNum){
    XMwayLoon::Randomizer::PhoneNumberRandomizer objPhNumRD;
    for(int i=0;i<100;i++)
    {
        std::string ss=objPhNumRD.generateEngPhNum(XMwayLoon::Randomizer::PhoneNumberRandomizer::CountryCodeFlag::random);
        std::cerr<<ss<<std::endl;

    }

}