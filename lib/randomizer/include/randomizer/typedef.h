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
#include "name_randomizer.h"


typedef XMwayLoon::Randomizer::BooleanRandomizer XMwayLoon_BooleanRandomizer;
typedef XMwayLoon::Randomizer::DateRandomizer XMwayLoon_DateRandomizer;
typedef XMwayLoon::Randomizer::NumberRandomizer XMwayLoon_NumberRandomizer;
typedef XMwayLoon::Randomizer::PangramRandomizer XMwayLoon_PangramRandomizer;
typedef XMwayLoon::Randomizer::PhoneNumberRandomizer XMwayLoon_PhoneNumberRandomizer;
typedef XMwayLoon::Randomizer::NameRandomizer XMwayLoon_NameRandomizer;
typedef XMwayLoon::Randomizer::NRCRandomizer XMwayLoon_NRCRandomizer;

#endif //XMWAYLOON_TYPEDEF_H
