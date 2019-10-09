//
// Created by Kaung Zaw Htet on 2019-10-08.
//

#include <gtest/gtest.h>
#include <iostream>


TEST(PhoneNumberTest,NumberTest1){
    std::cerr<<"This is Phone Number Text 1"<<std::endl;
    EXPECT_TRUE(true);

}

TEST(PhoneNumberTest,NumberTest2){
    EXPECT_TRUE(false);
    std::cerr<<"This is Phone Number Text 2"<<std::endl;
}