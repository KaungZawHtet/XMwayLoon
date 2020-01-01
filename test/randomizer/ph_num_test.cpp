//
// Created by Kaung Zaw Htet on 2019-10-08.
//

#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/ph_number_randomizer.h>

TEST(PhoneNumberTest,getRandomMyanPhNum){
    Xlotgative::ShinMwayLoon::PhoneNumberRandomizer objPhNumRD;
    for(int i=0;i<10;i++)
    {
        std::string ss=objPhNumRD.getRandomMyanPhNum(Xlotgative::ShinMwayLoon::PhoneNumberRandomizer::CountryCodeFlag::random);
        std::cerr<<ss<<std::endl;

    }

}
TEST(PhoneNumberTest,generateEngPhNum){
    Xlotgative::ShinMwayLoon::PhoneNumberRandomizer objPhNumRD;
    for(int i=0;i<100;i++)
    {
        std::string ss=objPhNumRD.generateEngPhNum(Xlotgative::ShinMwayLoon::PhoneNumberRandomizer::CountryCodeFlag::random);
        std::cerr<<ss<<std::endl;

    }

}