//
// Created by Kaung Zaw Htet on 2019-12-23.
//
#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/boolean_randomizer.h>
#include <ShinMwayLoon/global_objects.h>

typedef Xlotgative::ShinMwayLoon::BooleanRandomizer XMwayLoon_BooleanRandomizer;

TEST(BooleanTest,getNumBool){
    XMwayLoon_BooleanRandomizer obj_boolean;
   // XMwayLoon_BooleanRandomizer obj2= obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getAlphaBool(XMwayLoon::Encoding::Random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}

TEST(BooleanTest,getBoolean){
    XMwayLoon_BooleanRandomizer obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getBooleanRandomizer(XMwayLoon_BooleanRandomizer::type::num,XMwayLoon::Encoding::Random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}


TEST(BooleanTest,getAlphaBool){
    XMwayLoon_BooleanRandomizer obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getAlphaBool(XMwayLoon::Encoding::Random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}
