//
// Created by Kaung Zaw Htet on 2020-01-30.
//

#ifndef XMWAYLOON_CUSTOM_RANDOMIZER_H
#define XMWAYLOON_CUSTOM_RANDOMIZER_H

#include "faster_random.h"
#include "root_randomizer.h"
#include <model/type/enums.h>
#include <model/type/alphanumeric_type.h>
namespace XMwayLoon::Randomizer  {
    class CustomRandomizer : public RootRandomizer {

    private:
        std::vector<std::string> vecUniRecords;
        std::vector<std::string> vecZgRecords;
        XML_RE::Encoding encoding;
        
        CustomType objCustomType;
        std::string typeName;

        
        

    public:
        // explicit CustomRandomizer(const std::string& tmp_typeName,XML_RE::Encoding tmp_encoding=XML_RE::Encoding::unicode);
         std::string getRandom() override;
         explicit CustomRandomizer(CustomType tmp_objCustomType);
         void load() override ;
         
    };


}
#endif //XMWAYLOON_CUSTOM_RANDOMIZER_H
