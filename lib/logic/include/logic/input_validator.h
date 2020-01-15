//
// Created by Kaung Zaw Htet on 2019-12-28.
//

#ifndef XMWAYLOON_INPUT_VALIDATOR_H
#define XMWAYLOON_INPUT_VALIDATOR_H

#include <string>
#include <model/generate_info.h>
#include <logic/input_validator.h>
class InputValidator {
    const std::string errOutputFormat = "You need to select at least one output format";
    const std::string errTargetFile = "You need to choose generated file's target location";
    const std::string errDateFormat = "Invalid Date Format";
    const std::string warningPrefix= "Prefix look like unedited!. Are you sure to continue?";
    const std::string warningPostfix= "Postfix look like unedited!. Are you sure to continue?";

    GenerateInfo objGenerateInfo;
    InputValidator(GenerateInfo tmp_objGenerateInfo)
    : objGenerateInfo(std::move(tmp_objGenerateInfo)){}

    bool validate(const std::vector<std::string> &vecTypeNames,const std::vector<type> vecTypes);



};

#endif //XMWAYLOON_INPUT_VALIDATOR_H
