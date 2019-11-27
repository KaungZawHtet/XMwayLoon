//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef SHINMWAYLOON_GLOBAL_OBJECTS_H
#define SHINMWAYLOON_GLOBAL_OBJECTS_H

#include <ctime>
#include <memory>
#include <random>
#include "faster_random.h"
#include  <boost/random/random_device.hpp>



namespace Xlotgative::ShinMwayLoon{


   /// boost::random::random_device gen=boost::random::random_device();
  //  static  pcg generatorObject();
//static std::mt19937 generatorObject(static_cast<unsigned int>(time(0)));

    typedef  std::unique_ptr<std::string> ptr_string;
    enum class Encoding {Unicode=1,Zawgyi=2,Random=3};

};


#endif //SHINMWAYLOON_GLOBAL_OBJECTS_H
