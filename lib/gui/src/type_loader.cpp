//
// Created by Kaung Zaw Htet on 2019-12-17.
//
#include "../include/gui/type_loader.h"
#include <model/db/initializer.h>
TypeLoader::TypeLoader() {

    this->load();

}

void TypeLoader::load() {

    std::vector<std::string> tmpType= Initializer::storage
            .select(&CustomTypeName::type_name);


    TypeLoader::totalCount+= tmpType.size();


    TypeLoader::vecAllTypes.reserve(TypeLoader::totalCount);
    TypeLoader::vecAllTypes.insert(TypeLoader::vecAllTypes.end(), tmpType.begin(), tmpType.end());




}
