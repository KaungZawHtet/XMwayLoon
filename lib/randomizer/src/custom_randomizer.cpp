//
// Created by Kaung Zaw Htet on 2020-01-30.
//

#include <randomizer/custom_randomizer.h>
#include <randomizer/typedef.h>
#include <model/db/initializer.h>
using namespace sqlite_orm;
XMwayLoon_CustomRandomizer::CustomRandomizer
( const std::string& typeName,XML_RE::Encoding tmp_encoding)
: encoding(tmp_encoding)
{

    load();
}

std::string XMwayLoon_CustomRandomizer::getRandom
() {


    switch (encoding)
    {

        case XML_RE::Encoding::unicode : {
            std::uniform_int_distribution<> retrieveDistribution(0, vecUniRecords.size() - 1);
            int index = retrieveDistribution(this->objPCG);
            return this->vecUniRecords[index];
        }
            break;

        case XML_RE::Encoding::zawgyi : {
            std::uniform_int_distribution<> retrieveDistribution(0, vecZgRecords.size() - 1);
            int index = retrieveDistribution(this->objPCG);
            return this->vecZgRecords[index];
        }
            break;

        case XML_RE::Encoding::random :

            std::uniform_int_distribution<> encodingDistribution(0, 1);
            if (encodingDistribution(this->objPCG))
            {
                std::uniform_int_distribution<> retrieveDistribution(0, vecUniRecords.size()-1);
                int index= retrieveDistribution(this->objPCG);
                return this->vecUniRecords[index];
            }

            else
            {
                std::uniform_int_distribution<> retrieveDistribution(0, vecZgRecords.size()-1);
                int index= retrieveDistribution(this->objPCG);
                return this->vecZgRecords[index];
            }
            break;

    }
 
    
}

XMwayLoon_CustomRandomizer::CustomRandomizer(CustomType tmp_objCustomType)

:objCustomType(std::move(tmp_objCustomType))
{
    this->typeName=objCustomType.fieldName;
    this->encoding = objCustomType.encoding;
    load();

}

void XMwayLoon_CustomRandomizer::load() {
    //const std::string &typeName, XML_RE::Encoding tmp_encoding
    std::random_device objRandomDevice;
    this->objPCG.seed(objRandomDevice);
    switch (this->encoding)
    {

        case XML_RE::Encoding::unicode :

            this->vecUniRecords = Initializer::storage.select(&CustomTypeRecord::unicode_unit,
                                                              inner_join<CustomTypeName>
                                                                      (on(c(&CustomTypeName::id) == &CustomTypeRecord::custom_type_name_id
                                                                      )),
                                                              where(c(&CustomTypeName::type_name) == typeName)
            );


            break;
        case XML_RE::Encoding::zawgyi :
            this->vecZgRecords = Initializer::storage.select(&CustomTypeRecord::zawgyi_unit,
                                                             inner_join<CustomTypeName>
                                                                     (on(c(&CustomTypeName::id) == &CustomTypeRecord::custom_type_name_id
                                                                     )),
                                                             where(c(&CustomTypeName::type_name) == typeName)
            );
            break;
        case XML_RE::Encoding::random :

            this->vecUniRecords = Initializer::storage.select(&CustomTypeRecord::unicode_unit,
                                                              inner_join<CustomTypeName>
                                                                      (on(c(&CustomTypeName::id) == &CustomTypeRecord::custom_type_name_id
                                                                      )),
                                                              where(c(&CustomTypeName::type_name) == typeName)
            );

            this->vecZgRecords = Initializer::storage.select(&CustomTypeRecord::zawgyi_unit,
                                                             inner_join<CustomTypeName>
                                                                     (on(c(&CustomTypeName::id) == &CustomTypeRecord::custom_type_name_id
                                                                     )),
                                                             where(c(&CustomTypeName::type_name) == typeName)
            );

            break;

    }


}




