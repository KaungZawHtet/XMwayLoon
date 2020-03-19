//
// Created by Kaung Zaw Htet on 2020-01-27.
//

#ifndef XMWAYLOON_ORM_H
#define XMWAYLOON_ORM_H

struct CustomTypeRecord {
    int id;
    int custom_type_name_id;
    std::string unicode_unit;
    std::string zawgyi_unit;

};

struct CustomTypeName {

    int id;
    std::wstring type_name;
};





#endif //XMWAYLOON_ORM_H
