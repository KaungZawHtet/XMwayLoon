//
// Created by Kaung Zaw Htet on 2020-02-27.
//
#include <randomizer/name/name_randomizer.h>
#include <randomizer/typedef.h>
using namespace sqlite_orm;


XMwayLoon::Randomizer::ZgNameRandomizer::ZgNameRandomizer(NameType tmp_nameType)
: RootNameRandomizer(std::move(tmp_nameType)) {

    this->load();

    switch (this->objNameType.gender) {
        case XML_RE::Gender::male :
            this->loadMale();
            break;
        case XML_RE::Gender::female :
            this->loadFemale();
            break;
        case XML_RE::Gender::random :
            this->loadMale();
            this->loadFemale();
            break;
    }

}

void XMwayLoon::Randomizer::ZgNameRandomizer::loadFemale() {


    this->femaleSyllablesOne = storage.select(&XMwayLoon_RootNameRandomizer::Properties::zawgyi_syllable,
                                              where(
                                                      (c(&XMwayLoon_RootNameRandomizer::Properties::gender) !=1)
                                                      and
                                                      (c(&XMwayLoon_RootNameRandomizer::Properties::syllable_amount) == 1)
                                              ),
                                              order_by(sqlite_orm::random()));
    this->sizeFemaleOne = this->femaleSyllablesOne.size();


    this->femaleSyllablesTwo = storage.select(&XMwayLoon_RootNameRandomizer::Properties::zawgyi_syllable,
                                              where(
                                                      (c(&XMwayLoon_RootNameRandomizer::Properties::gender) !=1)
                                                      and
                                                      (c(&XMwayLoon_RootNameRandomizer::Properties::syllable_amount) == 2)
                                              ),
                                              order_by(sqlite_orm::random()));
    this->sizeFemaleTwo = this->femaleSyllablesTwo.size();
}

void XMwayLoon::Randomizer::ZgNameRandomizer::loadMale() {

    this->maleSyllablesOne = storage.select(&XMwayLoon_RootNameRandomizer::Properties::zawgyi_syllable,
                                            where(
                                                    (c(&XMwayLoon_RootNameRandomizer::Properties::gender) != 2)
                                                    and

                                                    (c(&XMwayLoon_RootNameRandomizer::Properties::syllable_amount) == 1)
                                            ),
                                            order_by(sqlite_orm::random()));
    this->sizeMaleOne = this->maleSyllablesOne.size();



    this->maleSyllablesTwo = storage.select(&XMwayLoon_RootNameRandomizer::Properties::zawgyi_syllable,
                                            where(
                                                    (c(&XMwayLoon_RootNameRandomizer::Properties::gender) != 2)
                                                    and
                                                    (c(&XMwayLoon_RootNameRandomizer::Properties::syllable_amount) == 2)
                                            ),
                                            order_by(sqlite_orm::random()));
    this->sizeMaleTwo = this->maleSyllablesTwo.size();
}

void XMwayLoon::Randomizer::ZgNameRandomizer::load() {
    std::random_device objRD;
    this->objPCG.seed(objRD);
}

