//
// Created by Kaung Zaw Htet on 2020-01-30.
//

#include <randomizer/custom_randomizer.h>
#include <randomizer/typedef.h>
#include <model/db/initializer.h>
using namespace sqlite_orm;
XMwayLoon_CustomRandomizer::CustomRandomizer
( std::string typeName,XMwayLoon::Randomizer::Encoding tmp_encoding)
: encoding(tmp_encoding)
{

    std::random_device objRandomDevice;
    this->objPCG.seed(objRandomDevice);
    switch (tmp_encoding)
    {

        case XMwayLoon::Randomizer::Encoding::unicode :

            this->vecUniRecords = Initializer::storage.select(&CustomTypeRecord::unicode_unit,
                                                          inner_join<CustomTypeName>
                                                                  (on(c(&CustomTypeName::id) == &CustomTypeRecord::custom_type_name_id
                                                                  )),
                                                                  where(c(&CustomTypeName::type_name) == typeName)
                    );

           
            break;
        case XMwayLoon::Randomizer::Encoding::zawgyi :
            this->vecZgRecords = Initializer::storage.select(&CustomTypeRecord::zawgyi_unit,
                                                              inner_join<CustomTypeName>
                                                                      (on(c(&CustomTypeName::id) == &CustomTypeRecord::custom_type_name_id
                                                                      )),
                                                              where(c(&CustomTypeName::type_name) == typeName)
            );
            break;
        case XMwayLoon::Randomizer::Encoding::random :
            
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

std::string XMwayLoon_CustomRandomizer::getRandomData
() {


    switch (encoding)
    {

        case XMwayLoon::Randomizer::Encoding::unicode : {
            std::uniform_int_distribution<> retrieveDistribution(0, vecUniRecords.size() - 1);
            int index = retrieveDistribution(this->objPCG);
            return this->vecUniRecords[index];
        }
            break;

        case XMwayLoon::Randomizer::Encoding::zawgyi : {
            std::uniform_int_distribution<> retrieveDistribution(0, vecZgRecords.size() - 1);
            int index = retrieveDistribution(this->objPCG);
            return this->vecZgRecords[index];
        }
            break;

        case XMwayLoon::Randomizer::Encoding::random :

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

