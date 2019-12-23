//
// Created by Kaung Zaw Htet on 2019-12-23.
//
#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/boolean.h>
#include <ShinMwayLoon/global_objects.h>

typedef Xlotgative::ShinMwayLoon::Boolean XMwayLoon_Boolean;

TEST(BooleanTest,getNumBool){
    XMwayLoon_Boolean obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getAlphaBool(XMwayLoon::Encoding::Random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}

TEST(BooleanTest,getBoolean){
    XMwayLoon_Boolean obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getBoolean(XMwayLoon_Boolean::type::num,XMwayLoon::Encoding::Random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}


TEST(BooleanTest,getAlphaBool){
    XMwayLoon_Boolean obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getAlphaBool(XMwayLoon::Encoding::Random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}
