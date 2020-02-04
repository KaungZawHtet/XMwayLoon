//
// Created by Kaung Zaw Htet on 2020-02-03.
//

#ifndef XMWAYLOON_GENERATION_H
#define XMWAYLOON_GENERATION_H

#include <logic/generation_task_manager/generator.h>
#include <model/generate_info.h>


class Loader
{
public:
    std::vector<type> vecTypes;
    void loadType()
    {

        vecTypes.reserve(7);


        BooleanType objBooleanType;
        objBooleanType.index = 0;
        objBooleanType.encoding = "Unicode";
        objBooleanType.fieldName = "Decider";
        objBooleanType.type = "၀/၁";
        
        DateType objDateType;
        objDateType.index=2;
        objDateType.encoding= "Unicode";
        objDateType.fieldName= "DOB";
        objDateType.format= "";
        
        NameType objNameType;
        objNameType.index=2;
        objNameType.encoding="Unicode";
        objNameType.fieldName="Employee";
        objNameType.gender="ကျပန်း";
        
        NRCType objNRCType;
        objNRCType.index=2;
        objNRCType.encoding="Unicode";
        objNRCType.fieldName="NRC";
        objNRCType.type="န";
        
        NumberType objNumberType;
        objNumberType.index=3;
        objNumberType.fieldName="Money";
        objNumberType.type="Rational";
        objNumberType.prefix="MM";
        objNumberType.postfix="Kyat";
        
        PangramType objPangramType;
        objPangramType.index=4;
        objPangramType.encoding="Random";
        objPangramType.fieldName="Pangram";
        
        PhNumberType objPhNumberType;
        objPhNumberType.index=5;
        objPhNumberType.fieldName="Caller";
        objPhNumberType.countryCode="Random";
        objPhNumberType.telecom="Random";

        vecTypes.emplace_back(objBooleanType);
        vecTypes.emplace_back(objDateType);
        vecTypes.emplace_back(objNameType);
        vecTypes.emplace_back(objNRCType);
        vecTypes.emplace_back(objNumberType);
        vecTypes.emplace_back(objPangramType);
        vecTypes.emplace_back(objPhNumberType);
    }

    void loadTypeName()
    {

    }

    void generate()
    {

    }



};

#endif //XMWAYLOON_GENERATION_H
