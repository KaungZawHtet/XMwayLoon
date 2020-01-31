//
// Created by Kaung Zaw Htet on 2019-12-17.
//
#include <logic/type_loader.h>
#include <model/db/initializer.h>
TypeLoader::TypeLoader() {

    this->load();

}

void TypeLoader::load() {

    std::vector<std::string> vecTypes= Initializer::storage
            .select(&CustomTypeName::type_name);



    TypeLoader::totalCount+= distance(vecTypes.begin(),vecTypes.end());

    TypeLoader::defaultType.reserve(TypeLoader::totalCount);
    TypeLoader::defaultType.insert(TypeLoader::defaultType.end(),vecTypes.begin(),vecTypes.end());



}
