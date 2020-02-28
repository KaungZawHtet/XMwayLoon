//
// Created by Kaung Zaw Htet on 2020-01-16.
//
#include <gtest/gtest.h>
#include <randomizer/name/name_randomizer.h>
#include <randomizer/typedef.h>
#include <model/db/initializer.h>
TEST(NameTest,getRandomName) {

    Initializer::initialize();

    NameType objNameType;

    objNameType.setEncoding("Random");
    objNameType.setGender("ကျပန်း");

    XMwayLoon_NameRandomizer objRan(objNameType);

    for (int i= 0;i  < 100; i++) {
        std::cerr<<  objRan.getRandom() << "\n";
    }

}

TEST(NameTest,getMaleName) {

    Initializer::initialize();

    NameType objNameType;

    objNameType.setEncoding("Unicode");
    objNameType.setGender("ကျား");

    XMwayLoon_NameRandomizer objRan(objNameType);

    for (int i= 0;i  < 100; i++) {
        std::cerr<<  objRan.getRandom() << "\n";
    }

}

TEST(NameTest,getFemaleName) {

    Initializer::initialize();

    NameType objNameType;

    objNameType.setEncoding("Unicode");
    objNameType.setGender("မ");

    XMwayLoon_NameRandomizer objRan(objNameType);

    for (int i= 0;i  < 100; i++) {
        std::cerr<<  objRan.getRandom() << "\n";
    }

}

TEST(NameTest,getZgUni) {
    Initializer::initialize();

    NameType objNameType;

    objNameType.setEncoding("Zawgyi");
    objNameType.setGender("ကျား");

    XMwayLoon_ZgNameRandomizer objRan(objNameType);

    std::cerr<<objRan.getRandom();






  /*  std::for_each( objRan.femaleSyllablesOne.begin() , objRan.femaleSyllablesOne.end()
            ,[](auto element){
        std::cerr<< element << "\n";

    });

    std::cerr<< "--------------------------------------- \n";

    std::for_each( objRan.femaleSyllablesTwo.begin() , objRan.femaleSyllablesTwo.end()
            ,[](auto element){
                std::cerr<< element << "\n";

            });
    std::cerr<< "--------------------------------------- \n";

    std::for_each( objRan.maleSyllablesOne.begin() , objRan.maleSyllablesOne.end()
            ,[](auto element){
                std::cerr<< element << "\n";

            });

    std::cerr<< "--------------------------------------- \n";
    std::for_each( objRan.maleSyllablesTwo.begin() , objRan.maleSyllablesTwo.end()
            ,[](auto element){
                std::cerr<< element << "\n";

            });*/
}