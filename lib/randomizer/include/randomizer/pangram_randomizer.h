//
// Created by Kaung Zaw Htet on 2019-10-04.
//

#ifndef SHINMWAYLOON_PANGRAM_H
#define SHINMWAYLOON_PANGRAM_H
#include "faster_random.h"
#include "root_randomizer.h"
#include <map>
#include <model/type/enums.h>
#include <model/type/numeric_type.h>
#include <model/type/alphanumeric_type.h>
namespace XMwayLoon::Randomizer
{
    class PangramRandomizer : public RootRandomizer
    {
        //first is alwasy unicode and second is zawgyi
        static constexpr std::pair<std::string_view,std::string_view> myanPangram{
                "သီဟိုဠ်မှ ဉာဏ်ကြီးရှင်သည် အာယုဝဍ္ဎနဆေးညွှန်းစာကို ဇလွန်ဈေးဘေး ဗာဒံပင်ထက် အဓိဋ္ဌာန်လျက် ဂဃနဏဖတ်ခဲ့သည််။",
                "သီဟိုဠ္မွ ဉာဏ္ႀကီးရွင္သည္ အာယုဝၯနေဆးၫႊန္းစာကို ဇလြန္ေဈးေဘး ဗာဒံပင္ထက္ အဓိ႒ာန္လ်က္ ဂဃနဏဖတ္ခဲ့သည္။"
        };

    private:
        pcg objPCG;
        PangramType objPangramType;

    public:
        std::string getPangram(XML_RE::Encoding encoding);
        PangramRandomizer();
        explicit PangramRandomizer(PangramType tmp_objPangramType);
        std::string getRandom() override;
        void load() override;



    };
}

#endif //SHINMWAYLOON_PANGRAM_H
