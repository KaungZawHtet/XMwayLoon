//
// Created by Kaung Zaw Htet on 2020-01-21.
//

#include "mmtext.h"

#include <gtest/gtest.h>
#include <parabaik/parabaik.h>
#include <unicode/errorcode.h>
#include <unicode/translit.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>



TEST(GeneralTest, Uni2ZgconversionTest) {
    zuconverter_open();
    char *outCStr = zawgyi_to_unicode("သီဟိုဠ္မွ ဥာဏ္ႀကီးရွင္သည္ အာယုဝၯနေဆးညႊန္းစာကို ဇလြန္ေဈးေဘးဗာဒံပင္ထက္ အဓိ႒ာန္လ်က္ ဂဃနဏဖတ္ခဲ့သည္။");
    printf("ZG => UNI: %s\n", outCStr);

    outCStr = unicode_to_zawgyi(outCStr);
    printf("UNI => ZG: %s\n", outCStr);

    free(outCStr);
    zuconverter_close();
}


TEST(GeneralTest, Zg2UniconversionTest) {
    const char* input1 = u8"အပြည်ပြည်ဆိုင်ရာ လူ့အခွင့်အရေး ကြေညာစာတမ်း";
    // Zawgyi string:
    const char* input2 = u8"အျပည္ျပည္ဆိုင္ရာ လူ႔အခြင့္အေရး ေၾကညာစာတမ္း";
    // Convert the second string to Unicode:
    static const auto* const converter = [] {
        icu::ErrorCode status;
        auto* converter = icu_63::Transliterator::createInstance(
                "Zawgyi-my", UTRANS_FORWARD  , status);

        return converter;
    }();
    icu::UnicodeString input2converted(input1);
    converter->transliterate(input2converted); // in-place conversion
    std::cerr << "Converted Text: " << input2converted << std::endl;

}


TEST(GeneralTest, encodingDetect) {

    if(MyanmarZawgyiConverter::isZawgyiEncoded("ကောင်းဇော်ထက်")) std::cerr<<"Unicode"<<"\n";
    else std::cerr<<"may be zawgyi"<<"\n";

    if(MyanmarZawgyiConverter::isZawgyiEncoded("ေကာင္းေဇာ္ထက္"))std::cerr<<"zawgyi"<<"\n";
    else std::cerr<<"may be unicode"<<"\n";

    //std::u16string st= u"";
}

TEST(GeneralTest, stringCheck) {

    std::string name="ကောင်းဇော်ထက်";
    std::wstring wname= L"ကောင်းဇော်ထက်";

   // std::cerr<< name << std::endl;
    std::wcout<< wname << std::endl;



}
