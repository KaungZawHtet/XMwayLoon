//
// Created by Kaung Zaw Htet on 2019-12-30.
//

#include <logic/generation_task_manager/generator.h>
#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>
#include <taskflow/taskflow.hpp>
#include <randomizer/boolean_randomizer.h>
#include <model/generate_info.h>
#include <model/type/enums.h>

using namespace XMwayLoon::Randomizer;

void Generator::generate() {



}


Generator::Generator(GenerateInfo tmp_objGenerateInfo)
        : objGenerateInfo(std::move(tmp_objGenerateInfo)) {
    auto size = objGenerateInfo.vecTypeNames.size();
    vecRanResults.reserve(size);
    vecRandomizers.reserve(size);


    this->taskRandomization = this->taskflow.emplace([&](tf::Subflow &subflow) {


        int count = 0;
        for (auto element : this->objGenerateInfo.vecTypeNames) {
            if (strcmp(element.c_str(), typeid(BooleanType).name()) == 0) {
                BooleanRandomizer objBoolRan;
                this->vecRandomizers.emplace_back(objBoolRan);

                //auto encoding =XML_RE::encodingMap[std::get<BooleanType>(this->objGenerateInfo.vecTypes[count]).encoding];
                auto type= [&](){
                   auto tmp_type= std::get<BooleanType>(this->objGenerateInfo.vecTypes[count]).type;
                    /*if((tmp_type.compare(BooleanRow::arrBoolType[0].ToStdString())) == 0){

                    }
*/

                };
               /* std::get<BooleanRandomizer>(this->vecRandomizers[count])
                        .getBooleanRandomizer
                                (std::get<BooleanType>(this->objGenerateInfo.vecTypes[count]).type,encoding);
*/

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


