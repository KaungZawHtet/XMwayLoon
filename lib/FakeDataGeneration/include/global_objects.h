//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef FAKEDATAGENERATOR_GLOBAL_OBJECTS_H
#define FAKEDATAGENERATOR_GLOBAL_OBJECTS_H
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

namespace Xlotgative{
static boost::random::mt19937 generatorObject(static_cast<unsigned int>(std::time(0)));

#define ZAWGYI "Zawgyi"
#define UNICODE "Unicode"

};


#endif //FAKEDATAGENERATOR_GLOBAL_OBJECTS_H
