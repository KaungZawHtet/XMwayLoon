//
// Created by Kaung Zaw Htet on 2020-01-16.
//
#include <gtest/gtest.h>
#include <randomizer/name_randomizer.h>
#include <randomizer/typedef.h>
#include <model/db/initializer.h>
TEST(NameTest,getFemaleName) {

    Initializer::initialize();

    XMwayLoon_NameRandomizer objRan
    (XMwayLoon_NameRandomizer::Gender::female
            ,XML_RE::Encoding::random);
    objRan.getFemaleName();


}
