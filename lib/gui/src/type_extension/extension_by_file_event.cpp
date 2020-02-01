//
// Created by Kaung Zaw Htet on 2020-01-28.
//

#include <gui/type_extension/extension_by_file_container.h>
#include <wx/dialog.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <gui/id.h>
#include <model/db/initializer.h>
#include <myanmar_encoding_handler/mmtext.h>
#include <gui/type_extension/read_me_dialog.h>
#include <myanmar_encoding_handler/parabaik.h>
#include <logic/type_loader.h>
using json = nlohmann::json;
using namespace std;

void ExtensionByFile_Container::onBrowse(wxCommandEvent &event) {

    wxFileDialog loadFileDialog(this, _("Choose your json file to extend : ")
            , "", "","", wxFD_FILE_MUST_EXIST);
    if (loadFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    // save the current contents in the file;
    // this can be done with e.g. wxWidgets output streams:

    this->path =loadFileDialog.GetPath();

    this->tcPath->SetValue(this->path);


    event.Skip();
}

void ExtensionByFile_Container::onExtend(wxCommandEvent &event) {


    wxMessageDialog dial = wxMessageDialog(NULL,
                                           wxT("Are you sure to continue?"), wxT("Confirmation"),
                                           wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    int result =dial.ShowModal();

    if(result ==wxID_YES) {

        try

        {
        // read a JSON file
        std::ifstream objStream(this->path);
        //  std::cerr<<path <<"\n";
        json objJson;
        objStream >> objJson;


        for (auto &element : objJson) {

            CustomTypeName objTypeName;
            objTypeName.id = -1;
            objTypeName.type_name = element["name"].get<std::string>();
            int idTypeName = Initializer::storage.insert(objTypeName);

            for (auto i : element["items"]) {
                CustomTypeRecord objCTR;
                objCTR.id = -1;
                objCTR.custom_type_name_id = idTypeName;

                std::string value = i.get<std::string>();
                if (mmtext::isZawgyiEncoded(value.c_str())) {
                    objCTR.zawgyi_unit = value;
                    objCTR.unicode_unit = zawgyi_to_unicode(value.c_str());

                } else {

                    objCTR.zawgyi_unit = value;
                    objCTR.unicode_unit = unicode_to_zawgyi(value.c_str());

                }
                Initializer::storage.insert(objCTR);

            }
            //Extend combobox at gen page
            cache::cbAddType->Append(objTypeName.type_name.data());


        }



    }
        catch (exception e){
            wxMessageDialog dial =  wxMessageDialog(NULL,
                                                        wxT("Error loading file"), wxT("Error"), wxOK | wxICON_ERROR);
            dial.ShowModal();

        }

    }

event.Skip();

}

void ExtensionByFile_Container::onReadMe(wxCommandEvent &event) {

    ReadMeDialog panel("Read Me");


    event.Skip();

}

