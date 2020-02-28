//
// Created by Kaung Zaw Htet on 2019-09-23.
//


#include <randomizer/name/name_randomizer.h>
#include <iostream>
#include <randomizer/typedef.h>


using namespace sqlite_orm;

std::string XMwayLoon_RootNameRandomizer::getFemaleName() {

    this->nameTypeDistribution = std::uniform_int_distribution<>(1, 6);
    int index = this->nameTypeDistribution(this->objPCG);

    switch (index) {
        case 1:
            return getOneOne(this->femaleSyllablesOne, this->sizeFemaleOne);
        case 2:
            return getOneOneOne(this->femaleSyllablesOne, this->sizeFemaleOne);
        case 3:
            return getOneTwo(this->femaleSyllablesOne, this->femaleSyllablesTwo, this->sizeFemaleOne,
                             this->sizeFemaleTwo);
        case 4:
            return getTwo(this->femaleSyllablesTwo, this->sizeFemaleTwo);
        case 5:
            return getTwoOne(this->femaleSyllablesOne, this->femaleSyllablesTwo, this->sizeFemaleOne,
                             this->sizeFemaleTwo);
        case 6 :
            return getTwoTwo(this->femaleSyllablesTwo, this->sizeFemaleTwo);

    }


}

std::string XMwayLoon_RootNameRandomizer::getMaleName() {

    this->nameTypeDistribution = std::uniform_int_distribution<>(1, 6);
    int index = this->nameTypeDistribution(this->objPCG);

    switch (index) {
        case 1:
            return getOneOne(this->maleSyllablesOne, this->sizeMaleOne);
        case 2:
            return getOneOneOne(this->maleSyllablesOne, this->sizeMaleOne);
        case 3:
            return getOneTwo(this->maleSyllablesOne, this->maleSyllablesTwo, this->sizeMaleOne, this->sizeMaleTwo);
        case 4:
            return getTwo(this->maleSyllablesTwo, this->sizeMaleTwo);
        case 5:
            return getTwoOne(this->maleSyllablesOne, this->maleSyllablesTwo, this->sizeMaleOne, this->sizeMaleTwo);
        case 6 :
            return getTwoTwo(this->maleSyllablesTwo, this->sizeMaleTwo);

    }

}

std::string XMwayLoon_RootNameRandomizer::getRandomName() {


    this->genderDistribution = std::uniform_int_distribution<>(0, 1);
    int index = this->genderDistribution(this->objPCG);

    if (index) return this->getMaleName();
    else  return this->getFemaleName();

}


std::string XMwayLoon_RootNameRandomizer::RootNameRandomizer::getRandom() {

    switch (this->objNameType.gender) {
        case XML_RE::Gender::male :
            return this->getMaleName();

        case XML_RE::Gender::female :
            return this->getFemaleName();

        case XML_RE::Gender::random :
            return this->getRandomName();
    }


}

void XMwayLoon_RootNameRandomizer::RootNameRandomizer::load() {
    std::random_device objRD;
    this->objPCG.seed(objRD);
}


std::string
XMwayLoon_RootNameRandomizer::getTwoOne(std::vector<std::string> &vecOne, std::vector<std::string> &vecTwo,
                                        int sizeOne, int sizeTwo) {

    this->oneDistribution = std::uniform_int_distribution<>(0, sizeOne - 1);
    this->twoDistribution = std::uniform_int_distribution<>(0, sizeTwo - 1);

    int indexOne = this->oneDistribution(this->objPCG);
    int indexTwo = this->twoDistribution(this->objPCG);

    return vecTwo[indexTwo] + vecOne[indexOne];


}

std::string XMwayLoon_RootNameRandomizer::getTwo(std::vector<std::string> &vecTwo, int sizeTwo) {


    this->twoDistribution = std::uniform_int_distribution<>(0, sizeTwo - 1);
    int indexTwo = this->twoDistribution(this->objPCG);

    return vecTwo[indexTwo];
}

std::string XMwayLoon_RootNameRandomizer::getTwoTwo(std::vector<std::string> &vecTwo, int sizeTwo) {

    this->twoDistribution = std::uniform_int_distribution<>(0, sizeTwo - 1);

    int indexOne = this->twoDistribution(this->objPCG);
    int indexTwo = this->twoDistribution(this->objPCG);

    return vecTwo[indexOne] + vecTwo[indexTwo];
}

std::string XMwayLoon_RootNameRandomizer::getOneOne(std::vector<std::string> &vecOne, int sizeOne) {
    this->oneDistribution = std::uniform_int_distribution<>(0, sizeOne - 1);

    int indexOne = this->oneDistribution(this->objPCG);
    int indexTwo = this->oneDistribution(this->objPCG);

    return vecOne[indexOne] + vecOne[indexTwo];
}

std::string XMwayLoon_RootNameRandomizer::getOneOneOne(std::vector<std::string> &vecOne, int sizeOne) {
    this->oneDistribution = std::uniform_int_distribution<>(0, sizeOne - 1);

    int indexOne = this->oneDistribution(this->objPCG);
    int indexTwo = this->oneDistribution(this->objPCG);
    int indexThree = this->oneDistribution(this->objPCG);

    return vecOne[indexOne] + vecOne[indexTwo] + vecOne[indexThree];
}

std::string
XMwayLoon_RootNameRandomizer::getOneTwo(std::vector<std::string> &vecOne, std::vector<std::string> &vecTwo,
                                        int sizeOne, int sizeTwo) {

    this->oneDistribution = std::uniform_int_distribution<>(0, sizeOne - 1);
    this->twoDistribution = std::uniform_int_distribution<>(0, sizeTwo - 1);

    int indexOne = this->oneDistribution(this->objPCG);
    int indexTwo = this->twoDistribution(this->objPCG);

    return vecOne[indexOne] + vecTwo[indexTwo];
}


XMwayLoon_RootNameRandomizer::RootNameRandomizer(NameType
tmp_nameType)
:

objNameType (std::move(tmp_nameType)) {
    //   storage.sync_schema()

}

/*  ----------------------------------------------------------------------------------------------------  */
/*  ----------------------------------------------------------------------------------------------------  */

std::string XMwayLoon_NameRandomizer::NameRandomizer::getRandom() {


    switch(this->encoding)
    {
        case XML_RE::Encoding ::unicode :
            return this->objUniNameRandomizer->getRandom();
            break;

        case XML_RE::Encoding::zawgyi :
            return this->objZgNameRandomizer->getRandom();
            break;

        case XML_RE::Encoding::random :

            this->encodingDistribution = std::uniform_int_distribution<>(0, 1);
            if(this->encodingDistribution(this->objPCG))
                return this->objZgNameRandomizer->getRandom() ;
            else
                return this->objUniNameRandomizer->getRandom();
            break;
    }

}

void XMwayLoon_NameRandomizer::NameRandomizer::load() {
    std::random_device objRD;
    this->objPCG.seed(objRD);
}



XMwayLoon_NameRandomizer::NameRandomizer(NameType
tmp_nameType) {

this->load();

    this->encoding = tmp_nameType.encoding;
switch(this->encoding)
    {
        case XML_RE::Encoding ::unicode :
        this->objUniNameRandomizer = new UniNameRandomizer(tmp_nameType);
        break;

        case XML_RE::Encoding::zawgyi :
        this->objZgNameRandomizer= new ZgNameRandomizer(tmp_nameType);
        break;

        case XML_RE::Encoding::random :
        this->objUniNameRandomizer = new UniNameRandomizer(tmp_nameType);
        this->objZgNameRandomizer= new ZgNameRandomizer(tmp_nameType);
        break;
    }


}
