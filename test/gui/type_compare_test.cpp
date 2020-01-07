//
// Created by Kaung Zaw Htet on 2019-12-29.
//

#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>
#include <gtest/gtest.h>
#include <any>
TEST(GUITest,typeCheck){

    std::vector<std::any> vecTypes;
    NumberType objNumberType;
    PhNumberType objPhNumberType;
    PangramType objPangramType;

    vecTypes.emplace_back(objNumberType);
    vecTypes.emplace_back(objPhNumberType);
    vecTypes.emplace_back(objPangramType);

    int count=0;

    std::for_each(vecTypes.begin(),vecTypes.end(),[&](std::any &element){

        if (strcmp(element.type().name()
                , typeid(NumberType).name()) == 0) {

            std::cerr<< "count is" <<count << " and type is" << element.type().name()<<std::endl;



        }
        else if (strcmp(element.type().name()
                , typeid(PhNumberType).name()) == 0) {

            std::cerr<< "count is" <<count << " and type is" << element.type().name()<<std::endl;

        }
        else if (strcmp(element.type().name()
                , typeid(PangramType).name()) == 0) {

            std::cerr<< "count is" <<count << " and type is" << element.type().name()<<std::endl;

        }
        count++;
    });
 //   std::cerr<<"Ans : " << typeid(PangramType).name() <<std::endl;





}