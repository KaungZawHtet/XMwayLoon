//
// Created by Kaung Zaw Htet on 2019-12-30.
//

#ifndef XMWAYLOON_TYPEDEF_H
#define XMWAYLOON_TYPEDEF_H

#include <variant>
#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>
#include <ShinMwayLoon/date_randomizer.h>
#include <ShinMwayLoon/boolean_randomizer.h>
#include <ShinMwayLoon/name_randomizer.h>
#include <ShinMwayLoon/nrc_randomizer.h>
#include <ShinMwayLoon/number_randomizer.h>
#include <ShinMwayLoon/pangram_randomizer.h>
#include <ShinMwayLoon/ph_number_randomizer.h>
#include <ShinMwayLoon/typedef.h>
typedef std::variant<BooleanType,DateType,NameType,NRCType,NumberType,PangramType,PhNumberType> type;
typedef std::variant<
        XMwayLoon::BooleanRandomizer
,XMwayLoon::DateRandomizer
,XMwayLoon::NameRandomizer
,XMwayLoon::NRCRandomizer
,XMwayLoon::NumberRandomizer
,XMwayLoon::PangramRandomizer
,XMwayLoon::PhoneNumberRandomizer
> randomizer;
#endif //XMWAYLOON_TYPEDEF_H
