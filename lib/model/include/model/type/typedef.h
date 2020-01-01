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
typedef std::variant<BooleanType,DateType,NameType,NRCType,NumberType,PangramType,PhNumberType> type;
typedef std::variant<Xlotgative::ShinMwayLoon::BooleanRandomizer
,Xlotgative::ShinMwayLoon::DateRandomizer
,Xlotgative::ShinMwayLoon::NameRandomizer
,Xlotgative::ShinMwayLoon::NRCRandomizer
,Xlotgative::ShinMwayLoon::NumberRandomizer
,Xlotgative::ShinMwayLoon::PangramRandomizer
,Xlotgative::ShinMwayLoon::PhoneNumberRandomizer> randomizer;
#endif //XMWAYLOON_TYPEDEF_H
