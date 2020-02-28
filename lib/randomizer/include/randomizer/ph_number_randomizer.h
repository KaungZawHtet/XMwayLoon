//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef SHINMWAYLOON_PH_NUMBER_H
#define SHINMWAYLOON_PH_NUMBER_H
#include "faster_random.h"
#include "root_randomizer.h"
#include <map>
#include <array>
#include <boost/logic/tribool.hpp>
#include <randomizer/number_randomizer.h>
#include <model/type/numeric_type.h>
#include <model/type/alphanumeric_type.h>
#include <randomizer/ph_num/mpt.h>
#include <randomizer/ph_num/mytel.h>
#include <randomizer/ph_num/ooredoo.h>
#include <randomizer/ph_num/telenor.h>
namespace XMwayLoon::Randomizer {

    class PhoneNumberRandomizer : public RootRandomizer

            {




    private:

        PhNumberType objPhNumberType;



        std::vector<RootRandomizer*> vecTelecom;



    public:



        explicit PhoneNumberRandomizer(PhNumberType tmp_objPhNumberType);
        std::string getRandom () override ;
        ~PhoneNumberRandomizer();
        void load() override ;
       // std::string getRandomPhNum()  ;


    };
};

#endif //SHINMWAYLOON_PH_NUMBER_H
