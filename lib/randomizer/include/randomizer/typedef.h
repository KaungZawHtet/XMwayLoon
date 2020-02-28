//
// Created by Kaung Zaw Htet on 2020-01-04.
//

#ifndef XMWAYLOON_TYPEDEF_H
#define XMWAYLOON_TYPEDEF_H


#include "boolean_randomizer.h"
#include "date_randomizer.h"
#include "number_randomizer.h"
#include "pangram_randomizer.h"
#include "ph_number_randomizer.h"
#include "nrc_randomizer.h"
#include "randomizer/name/name_randomizer.h"
#include "custom_randomizer.h"


typedef XMwayLoon::Randomizer::BooleanRandomizer XMwayLoon_BooleanRandomizer;
typedef XMwayLoon::Randomizer::DateRandomizer XMwayLoon_DateRandomizer;
typedef XMwayLoon::Randomizer::NumberRandomizer XMwayLoon_NumberRandomizer;
typedef XMwayLoon::Randomizer::PangramRandomizer XMwayLoon_PangramRandomizer;
typedef XMwayLoon::Randomizer::PhoneNumberRandomizer XMwayLoon_PhoneNumberRandomizer;
typedef XMwayLoon::Randomizer::NameRandomizer XMwayLoon_NameRandomizer;
typedef XMwayLoon::Randomizer::NRCRandomizer XMwayLoon_NRCRandomizer;
typedef XMwayLoon::Randomizer::ZgNameRandomizer XMwayLoon_ZgNameRandomizer;
typedef XMwayLoon::Randomizer::UniNameRandomizer XMwayLoon_UniNameRandomizer;
typedef XMwayLoon::Randomizer::RootNameRandomizer XMwayLoon_RootNameRandomizer;
typedef XMwayLoon::Randomizer::CustomRandomizer XMwayLoon_CustomRandomizer;
#endif //XMWAYLOON_TYPEDEF_H
