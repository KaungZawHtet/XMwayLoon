//
// Created by Kaung Zaw Htet on 2020-01-21.
//
#ifndef XMWAYLOON_MMTEXT_H
#define XMWAYLOON_MMTEXT_H
#include <boost/regex/icu.hpp>
#include <regex>
#include <boost/regex.hpp>
#include <boost/regex/icu.hpp>
#include <boost/regex.hpp>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <unicode/regex.h>

class MyanmarZawgyiConverter {

public:
    static inline bool isZawgyiEncoded(const icu_65::UnicodeString& value)
 {
     const icu_65::UnicodeString rule="[\u105a\u1060-\u1097]|[\u1033\u1034]|\u1031\u108f|\u1031[\u103b-\u103e]|[\u102b-\u1030\u1032]\u1031| \u1031| \u103b|^\u1031|^\u103b|\u1038\u103b|\u1038\u1031|[\u102d\u102e\u1032]\u103b|\u1039[^\u1000-\u1021]|\u1039$|\u1004\u1039[\u1001-\u102a\u103f\u104e]|\u1039[^u1000-\u102a\u103f\u104e]|\u103c\u103b|\u103d\u103b|\u103e\u103b|\u103d\u103c|\u103e\u103c|\u103e\u103d|\u103b\u103c|[\u102f\u1030\u102b\u102c][\u102d\u102e\u1032]|[\u102b\u102c][\u102f\u102c]|[\u1040-\u1049][\u102b-\u103e\u102b-\u1030\u1032\u1036\u1037\u1038\u103a]|^[\u1040\u1047][^\u1040-\u1049]|[\u1000-\u102a\u103f\u104e]\u1039[\u101a\u101b\u101d\u101f\u1022-\u103f]|\u103a\u103e|\u1036\u102b]|\u102d[\u102e\u1032]|\u102e[\u102d\u1032]|\u1032[\u102d\u102e]|\u102f\u1030|\u1030\u102f|\u102b\u102c|\u102c\u102b|[\u1090-\u1099][\u102b-\u1030\u1032\u1037\u103a-\u103e]|[\u1000-\u10f4][\u1090-\u1099][\u1000-\u104f]|^[\u1090-\u1099][\u1000-\u102a\u103f\u104e\u104a\u104b]|[\u1000-\u104f][\u1090-\u1099]$|[\u105e-\u1060\u1062-\u1064\u1067-\u106d\u1071-\u1074\u1082-\u108d\u108f\u109a-\u109d][\u102b-\u103e]|[\u1000-\u102a]\u103a[\u102d\u102e\u1032]|[\u102b-\u1030\u1032\u1036-\u1038\u103a]\u1031|[\u1087-\u108d][\u106e-\u1070\u1072-\u1074]|^[\u105e-\u1060\u1062-\u1064\u1067-\u106d\u1071-\u1074\u1082-\u108d\u108f\u109a-\u109d]|[\u0020\u104a\u104b][\u105e-\u1060\u1062-\u1064\u1067-\u106d\u1071-\u1074\u1082-\u108d\u108f\u109a-\u109d]|[\u1036\u103a][\u102d-\u1030\u1032]|[\u1025\u100a]\u1039|[\u108e-\u108f][\u1050-\u108d]|\u102d-\u1030\u1032\u1036-\u1037]\u1039]|[\u1000-\u102a\u103f\u104e]\u1037\u1039|[\u1000-\u102a\u103f\u104e]\u102c\u1039[\u1000-\u102a\u103f\u104e]|[\u102b-\u1030\u1032][\u103b-\u103e]|\u1032[\u103b-\u103e]|\u101b\u103c|[\u1000-\u102a\u103f\u104e]\u1039[\u1000-\u102a\u103f\u104e]\u1039[\u1000-\u102a\u103f\u104e]|[\u1000-\u102a\u103f\u104e]\u1039[\u1000-\u102a\u103f\u104e][\u102b\u1032\u103d]|[\u1000\u1005\u100f\u1010\u1012\u1014\u1015\u1019\u101a]\u1039\u1021|[\u1000\u1010]\u1039\u1019|\u1004\u1039\u1000|\u1015\u1039[\u101a\u101e]|\u1000\u1039\u1001\u1036|\u1039\u1011\u1032|\u1037\u1032|\u1036\u103b|\u102f\u102f";


     UErrorCode status= U_ZERO_ERROR;
     icu_65::RegexMatcher matcher =  icu_65::RegexMatcher(rule, 0, status);


     matcher.reset(value);
   //  std::string s = "Boost C++ Libraries";
   //  std::cout << boost::to_upper_copy(s) << '\n';


     return matcher.find();

   //  return boost::u32regex_match(value, boost::make_u32regex(rule));
    // std::wregex objWRegex(rule);
    // std::wsmatch rm;
    // return std::regex_match(value,  objWRegex);

    }



};


#endif 