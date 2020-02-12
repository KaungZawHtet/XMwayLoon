//
// Created by Kaung Zaw Htet on 2019-10-08.
//

#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/ph_number_randomizer.h>

#include <model/type/numeric_type.h>


TEST(PhoneNumberTest,getRandomMyanPhNum){

//"09...", "+959...","959...","random"
    PhNumberType obj;
    obj.setTelecom("MPT");
    obj.setCountryCodeFlag("+959...");



    XMwayLoon::Randomizer::PhoneNumberRandomizer objPhNumRD(obj);
    for(int i=0;i<10;i++)
    {
        std::string ss=objPhNumRD.getRandom();
        std::cerr<<ss<<std::endl;

    }

}
