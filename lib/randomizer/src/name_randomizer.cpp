//
// Created by Kaung Zaw Htet on 2019-09-23.
//


#include <randomizer/name_randomizer.h>
#include <randomizer/global_objects.h>
#include <iostream>
#include <randomizer/typedef.h>



using namespace sqlite_orm;

std::string XMwayLoon_NameRandomizer::getFemaleName() {




    //   storage.sync_schema();

    auto femaleSyllables = storage.select(&XMwayLoon_NameRandomizer::Properties::unicode_syllable,
                                          where(
                                                  (c(&XMwayLoon_NameRandomizer::Properties::gender) == (int) this->objNameType.gender)
                                                  and
                                                  (c(&XMwayLoon_NameRandomizer::Properties::syllable_amount) == 2)
                                          ),
                                          order_by(sqlite_orm::random()),
                                          limit(100));

   std::cerr<< typeid(femaleSyllables).name()<<std::endl;

    for (auto &element : femaleSyllables) {
        std::cerr << element << std::endl;
    }

    return "";
}

std::string XMwayLoon_NameRandomizer::getMaleName() {

    return "";

}

std::string XMwayLoon_NameRandomizer::getRandomName() {

    return "";

}

std::string XMwayLoon_NameRandomizer::getName() {

    return std::string("နာမည်တု");



}

XMwayLoon_NameRandomizer::NameRandomizer(NameType tmp_nameType)
: objNameType (std::move(tmp_nameType)) {


    std::random_device objRD;
    this->objPCG.seed(objRD);


}



