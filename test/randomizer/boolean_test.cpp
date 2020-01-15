//
// Created by Kaung Zaw Htet on 2019-12-23.
//
#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/boolean_randomizer.h>
#include <randomizer/global_objects.h>

typedef XMwayLoon::Randomizer::BooleanRandomizer XMwayLoon_BooleanRandomizer;

TEST(BooleanTest,getNumBool){
    XMwayLoon_BooleanRandomizer obj_boolean;
   // XMwayLoon_BooleanRandomizer obj2= obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getAlphaBool(XMwayLoon::Randomizer::Encoding::random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}

TEST(BooleanTest,getBoolean){
    XMwayLoon_BooleanRandomizer obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getBooleanRandomizer(XMwayLoon_BooleanRandomizer::type::num,XMwayLoon::Randomizer::Encoding::random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}


TEST(BooleanTest,getAlphaBool){
    XMwayLoon_BooleanRandomizer obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getAlphaBool(XMwayLoon::Randomizer::Encoding::random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}
