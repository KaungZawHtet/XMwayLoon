//
// Created by Kaung Zaw Htet on 2019-11-24.
//

#include <gtest/gtest.h>
#include <iostream>
#include <ShinMwayLoon/ph_number.h>
#include <ShinMwayLoon/faster_random.h>
#include <random>
using namespace std;
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

template<typename T>
void showMinMax() {
    cout << "min: " << numeric_limits<T>::min() << endl;
    cout << "max: " << numeric_limits<T>::max() << endl;
    cout << endl;
}

TEST(GeneralTest,limit){

    cout << "short:" << endl;
    showMinMax<short>();
    cout << "int:" << endl;
    showMinMax<int>();
    cout << "long:" << endl;
    showMinMax<long>();
    cout << "float:" << endl;
    showMinMax<float>();
    cout << "double:" << endl;
    showMinMax<double>();
    cout << "long double:" << endl;
    showMinMax<long double>();
    cout << "unsigned short:" << endl;
    showMinMax<unsigned short>();
    cout << "unsigned int:" << endl;
    showMinMax<unsigned int>();
    cout << "unsigned long:" << endl;
    showMinMax<unsigned long>();


}

TEST(GeneralTest,uniqueToArr){

   auto a= std::make_unique<std::string[]>(100);
    /*a[0]= "h";
    a[1]= "rw";
    a[2]= "rwh";
    a[3]= "egeg";
    a[4]= "rgwgwh";
    a[5]= "g3g";*/

    int count = sizeof(a)/ sizeof(a[0]);

   for (int i=0; i < 6; i++)
   {
       cout<<a[i] <<endl;

   }


}