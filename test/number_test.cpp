//
// Created by Kaung Zaw Htet on 2019-10-08.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../lib/ShinMwayLoon/include/ph_number.h"


TEST(NumberTest,NumberTest1){
    std::cerr<<"This is number test 1"<<std::endl;
    EXPECT_TRUE(true);

}

TEST(NumberTest,NumberTest2){
    EXPECT_TRUE(false);
    std::cerr<<"This is number test 2"<<std::endl;
}