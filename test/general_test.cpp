//
// Created by Kaung Zaw Htet on 2019-11-24.
//

#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/ph_number.h>
#include <ShinMwayLoon/faster_random.h>
#include <random>

TEST(GeneralTest,fasterRandom){

    std::random_device gen;
    pcg generatorObject(gen);
    std::uniform_int_distribution<int> myanNumDistribution(1, 1000);

    for (int i = 0; i < 100; ++i) {

      //  boost::random::random_device gen=boost::random::random_device();
        std::cout<< myanNumDistribution(generatorObject)<<std::endl;
        // std::mt19937 generatorObject(static_cast<unsigned int>(time(0)));

    }


}