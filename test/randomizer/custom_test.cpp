//
// Created by Kaung Zaw Htet on 2020-01-30.
//

#include <gtest/gtest.h>
#include <iostream>
#include <randomizer/custom_randomizer.h>
#include <model/db/initializer.h>
using namespace sqlite_orm;
typedef XMwayLoon::Randomizer::CustomRandomizer XMwayLoon_CustomRandomizer;

TEST(CustomTest,getData){

    XMwayLoon_CustomRandomizer obj("myself",XML_RE::Encoding::unicode);

    for (int i = 0; i < 10; ++i) {
       std::cerr<< obj.getRandom() << '\n';
    }
}

TEST(CustomTest,VceTest){
   auto a = Initializer::storage.select(&CustomTypeRecord::zawgyi_unit,
                                  inner_join<CustomTypeName>
                                          (on(c(&CustomTypeName::id) == &CustomTypeRecord::custom_type_name_id
                                          )),
                                  where(c(&CustomTypeName::type_name) == "myself")
    );

   for( auto &element  : a)
   {
       std::cerr << element << std::endl;

   }

}
