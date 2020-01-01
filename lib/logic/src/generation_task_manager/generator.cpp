//
// Created by Kaung Zaw Htet on 2019-12-30.
//

#include <logic/generation_task_manager/generator.h>
#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>
#include <taskflow/taskflow.hpp>

void Generator::generate() {}

Generator::Generator(GenerateInfo tmp_objGenerateInfo)
    : objGenerateInfo(std::move(tmp_objGenerateInfo))
    {
        vecRanResults.reserve(objGenerateInfo.vecTypeNames.size());
        vecRandomizers.reserve(objGenerateInfo.vecTypeNames.size());

        this->taskRandomization = this->taskflow.emplace([&] (tf::Subflow& subflow) {

            int count = 0;
            for ( auto element : this->objGenerateInfo.vecTypeNames)
            {
                if (strcmp(element.c_str(), typeid(BooleanType).name()) == 0) {
                    this->vecRandomizers[count]=Xlotgative::ShinMwayLoon::BooleanRandomizer;

                    tf::Task taskBoolRD=subflow.emplace([](){}).name("taskBoolRD");


                } else if (strcmp(element.c_str(), typeid(DateType).name()) == 0) {

                } else if (strcmp(element.c_str(), typeid(NameType).name()) == 0) {


                } else if (strcmp(element.c_str(), typeid(NRCType).name()) == 0) {

                } else if (strcmp(element.c_str(), typeid(NumberType).name()) == 0) {

                } else if (strcmp(element.c_str(), typeid(PangramType).name()) == 0) {


                } else if (strcmp(element.c_str(), typeid(PhNumberType).name()) == 0) {

                } else {

                }


                ++count;
            }


        }).name("taskRandomization");





    }


