//
// Created by Kaung Zaw Htet on 2020-01-25.
//
#include <gui/type_extension/extension_manually_container.h>
#include <myanmar_encoding_handler/mmtext.h>
#include <myanmar_encoding_handler/parabaik.h>
#include <dry_comparisons/dry_comparisons.h>
#include <unicode/errorcode.h>
#include <string>
#include <gui/type_loader.h>
#include <gui/id.h>

void ExtensionManually_Container::onInsert(wxCommandEvent &event) {
    this->appendRecordList();
    event.Skip();

}


void ExtensionManually_Container::onRemove(wxCommandEvent &event) {

    if( rollbear::all_of (0,this->indexLB) < this->lbUnicode->GetCount()  )
    {


        this->lbUnicode->Delete(this->indexLB );
        this->lbZawgyi->Delete(this->indexLB);
     //   this->vecUniRecords.erase(vecUniRecords.begin() + this->indexLB);
       // this->vecZgRecords.erase(vecZgRecords.begin() + this->indexLB);
        this->vecRecords.erase(vecRecords.begin()+ this->indexLB);

       // std::string a ="indexLb : " + std::to_string( this->indexLB ) + " GetCount : " + std::to_string(this->lbZawgyi->GetCount())  ;
        //this->stError->SetLabelText(a);
    }


    event.Skip();
}

void ExtensionManually_Container::onSelect(wxCommandEvent &event) {

    this->indexLB=event.GetSelection();
    event.Skip();
}


void ExtensionManually_Container::onRecordEnter(wxCommandEvent &event) {

  this->appendRecordList();
    event.Skip();

}


void ExtensionManually_Container::onExtend(wxCommandEvent &event) {

    wxMessageDialog dial = wxMessageDialog(NULL,
                                                wxT("Are you sure to continue?"), wxT("Confirmation"),
                                                wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    int result =dial.ShowModal();

    if(result ==wxID_YES)
    {
        std::string value(this->tcTypeName->GetValue().c_str());

        if (value.compare("")==0) // not to become empty type name
        {
            this->stError->SetLabelText("Type name required!");
            this->stError->SetForegroundColour(wxColor(*wxRED));

        } else{
            if(this->strTypeName.compare(this->tcTypeName->GetValue())==0) // not to become duplicate extension
            {
                this->stError->SetLabelText("This type already extended!");
                this->stError->SetForegroundColour(wxColor(*wxRED));
            } else{

                this->stError->SetLabelText("");

                CustomTypeName objTypeName;
                objTypeName.id=-1;
                objTypeName.type_name=this->tcTypeName->GetValue();
                this->strTypeName=this->tcTypeName->GetValue(); // not to become duplicate extension

                int idTypeName=Initializer::storage.insert(objTypeName);
                std::for_each(vecRecords.begin(),vecRecords.end(),[&](CustomTypeRecord element){
                    element.custom_type_name_id= idTypeName;
                    Initializer::storage.insert(element);});



                //Extend combobox at gen page
                WidgetsCache::cbAddType->Append(objTypeName.type_name.data());
                WidgetsCache::objTypeLoader->load();
            }

        }



    }





    event.Skip();



}



void ExtensionManually_Container::appendRecordList() {

    std::string value(this->tcRecord->GetValue().c_str());

    if (value.compare("")==0)
    {
        this->stError->SetLabelText("Empty record!");
        this->stError->SetForegroundColour(wxColor(*wxRED));

    } else{

        this->stError->SetLabelText("");

        CustomTypeRecord objCTR;
        objCTR.id=-1;

        std::string value( this->tcRecord->GetValue().c_str());
        if(mmtext::isZawgyiEncoded(value.c_str()))
        {
            this->lbZawgyi->Append(value);
            objCTR.zawgyi_unit=value;
            //   this->vecZgRecords.emplace_back(value);

            std::string uniValue( zawgyi_to_unicode(value.c_str()) );
            this->lbUnicode->Append(uniValue);
            objCTR.unicode_unit=uniValue;
            //    this->vecUniRecords.emplace_back(uniValue);
            this->vecRecords.emplace_back(objCTR);
        } else
        {
            this->lbUnicode->Append(value);
            objCTR.unicode_unit=value;
            //  this->vecUniRecords.emplace_back(value);

            std::string zgValue( unicode_to_zawgyi(value.c_str()) );
            this->lbZawgyi->Append(zgValue);
            objCTR.zawgyi_unit=zgValue;
            //   this->vecZgRecords.emplace_back(zgValue);
            this->vecRecords.emplace_back(objCTR);

        }


    }

}




