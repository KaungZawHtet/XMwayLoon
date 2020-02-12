//
// Created by Kaung Zaw Htet on 2019-11-22.
//


#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/pangram_randomizer.h>
#include <model/type/alphanumeric_type.h>


TEST(PangramTest,getPangram){
    
    PangramType objPangramType;
    objPangramType.encoding=XML_RE::Encoding::random;

    XMwayLoon::Randomizer::PangramRandomizer objPangramRandomizer(objPangramType);
    std::string myanNum =objPangramRandomizer.getRandom();
    std::cerr<<myanNum<<std::endl;
}