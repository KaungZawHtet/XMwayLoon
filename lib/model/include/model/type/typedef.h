//
// Created by Kaung Zaw Htet on 2019-12-30.
//

#ifndef XMWAYLOON_TYPEDEF_H
#define XMWAYLOON_TYPEDEF_H

#include <variant>
#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>
#include <randomizer/date_randomizer.h>
#include <randomizer/boolean_randomizer.h>
#include <randomizer/name_randomizer.h>
#include <randomizer/nrc_randomizer.h>
#include <randomizer/number_randomizer.h>
#include <randomizer/pangram_randomizer.h>
#include <randomizer/ph_number_randomizer.h>
#include <randomizer/typedef.h>
#include <randomizer/custom_randomizer.h>

typedef std::variant<BooleanType,DateType,NameType,NRCType,NumberType,PangramType,PhNumberType,CustomType> type;
typedef std::variant<
        XMwayLoon::Randomizer::BooleanRandomizer
,XMwayLoon::Randomizer::DateRandomizer
,XMwayLoon::Randomizer::NameRandomizer
,XMwayLoon::Randomizer::NRCRandomizer
,XMwayLoon::Randomizer::NumberRandomizer
,XMwayLoon::Randomizer::PangramRandomizer
,XMwayLoon::Randomizer::PhoneNumberRandomizer
,XMwayLoon::Randomizer::CustomRandomizer
> randomizer;
#endif //XMWAYLOON_TYPEDEF_H
