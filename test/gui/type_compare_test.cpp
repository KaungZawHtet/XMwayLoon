//
// Created by Kaung Zaw Htet on 2019-12-29.
//

#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>
#include <gtest/gtest.h>
#include <any>
#include <wx/wx.h>
#include <array>

//constexpr member
class car
{
private:
    static constexpr int wheel=14567;
  std::array<std::string, 2> params2 = {{"foo" ,"bar"}};

public:
    static constexpr int getWheel()
    {
        return wheel;
    }
};
//constexpr user defined obj
class animal
{
public:
    int a=2,b=4;
    constexpr animal()= default;
    constexpr animal(int tmp_a,int tmp_b): a(tmp_a), b(tmp_b){}
};


TEST(GUITest, constexprObjTest)

{
    animal a;

    std::cout<<"wheel is"<<a.a;

}


TEST(GUITest,stringCompare)
{
    wxString wxStr1("Hello");
    wxString wxStr2("123");
    wxString wxStr3("ကောင်းဇော်ထက်");


    std::string stdStr1("Hello");
    std::string stdStr2("၁၂၃");
    std::string stdStr3("ကောင်းဇော်ထက်");

    if(stdStr1==wxStr1) { std::cerr<< "First One Right"<<'\n'; }
    else{std::cerr<< "First One Wrong"<<'\n';}

    if(stdStr2==wxStr2) { std::cerr<< "Second One Right"<<'\n'; }
    else{std::cerr<< "Second One Wrong"<<'\n';}

    if(stdStr3==wxStr3) { std::cerr<< "Third One Right"<<'\n'; }
    else{std::cerr<< "Third One Wrong"<<'\n';}



}
TEST(GUITest,typeCheck){

    std::vector<std::any> vecTypes;
    NumberType objNumberType;
    PhNumberType objPhNumberType;
    PangramType objPangramType;

    vecTypes.emplace_back(objNumberType);
    vecTypes.emplace_back(objPhNumberType);
    vecTypes.emplace_back(objPangramType);

    int count=0;

    std::for_each(vecTypes.begin(),vecTypes.end(),[&](std::any &element){

        if (strcmp(element.type().name()
                , typeid(NumberType).name()) == 0) {

            std::cerr<< "count is" <<count << " and type is" << element.type().name()<<std::endl;



        }
        else if (strcmp(element.type().name()
                , typeid(PhNumberType).name()) == 0) {

            std::cerr<< "count is" <<count << " and type is" << element.type().name()<<std::endl;

        }
        else if (strcmp(element.type().name()
                , typeid(PangramType).name()) == 0) {

            std::cerr<< "count is" <<count << " and type is" << element.type().name()<<std::endl;

        }
        count++;
    });
 //   std::cerr<<"Ans : " << typeid(PangramType).name() <<std::endl;





}



