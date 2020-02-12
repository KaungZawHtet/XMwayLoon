//
// Created by Kaung Zaw Htet on 2019-12-23.
//
#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/boolean_randomizer.h>
#include "types.h"

typedef XMwayLoon::Randomizer::BooleanRandomizer XMwayLoon_BooleanRandomizer;

TEST(BooleanTest,getNumBool){

    BooleanType objBoolType;
    objBoolType.type=XML_RE::BoolType::alpha;
    objBoolType.encoding=XML_RE::Encoding::random;

    XMwayLoon_BooleanRandomizer obj_boolean(objBoolType);
   // XMwayLoon_BooleanRandomizer obj2= obj_boolean;
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getAlphaBool(XML_RE::Encoding::random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}

TEST(BooleanTest,getBoolean){
    BooleanType objBoolType;
    objBoolType.type=XML_RE::BoolType::alpha;
    objBoolType.encoding=XML_RE::Encoding::random;

    XMwayLoon_BooleanRandomizer obj_boolean(objBoolType);
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getBoolRandom(XML_RE::BoolType::alpha, XML_RE::Encoding::random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}


TEST(BooleanTest,getAlphaBool){
    BooleanType objBoolType;
    objBoolType.type=XML_RE::BoolType::alpha;
    objBoolType.encoding=XML_RE::Encoding::random;

    XMwayLoon_BooleanRandomizer obj_boolean(objBoolType);
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getAlphaBool(XML_RE::Encoding::random);
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}

TEST(BooleanTest,getRandom){
    BooleanType objBoolType;
    objBoolType.type=XML_RE::BoolType::alpha;
    objBoolType.encoding=XML_RE::Encoding::unicode;

    XMwayLoon_BooleanRandomizer obj_boolean(objBoolType);
    for (int i=0 ; i <10; i++)
    {
        std::string strBoolean= obj_boolean.getRandom();
        std::cerr<<"Ans : " <<strBoolean <<std::endl;
    }

}