//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef SHINMWAYLOON_GLOBAL_OBJECTS_H
#define SHINMWAYLOON_GLOBAL_OBJECTS_H
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <ctime>
#include <memory>


namespace Xlotgative::ShinMwayLoon{
static boost::random::mt19937 generatorObject(static_cast<unsigned int>(time(0)));

    typedef  std::unique_ptr<std::string> ptr_string;
    enum class Encoding {Unicode=1,Zawgyi=2,Random=3};







};


#endif //SHINMWAYLOON_GLOBAL_OBJECTS_H
