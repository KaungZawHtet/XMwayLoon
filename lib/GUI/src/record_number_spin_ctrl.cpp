
#include <wx/wx.h>
#include <gui/record_number_spin_ctrl.h>
#include <wx/valnum.h>
#include <gui/id.h>

void RecordNumberSpinCtrl::SpinUp(wxSpinEvent &event)
{
    wxMessageDialog *dial = new wxMessageDialog(this->parent,
       wxT("Error loading file"), wxT("Error"));
    dial->ShowModal();

}

void RecordNumberSpinCtrl::SpinDown(wxSpinEvent &event)
{
    wxMessageDialog *dial = new wxMessageDialog(this->parent,
       wxT("Error loading file"), wxT("Error"));
    dial->ShowModal();
}



RecordNumberSpinCtrl::RecordNumberSpinCtrl(wxWindow *parent)
{
    this->parent= parent;
    wxIntegerValidator<unsigned long>
            val(&(this->value), wxNUM_VAL_THOUSANDS_SEPARATOR);
    this->bsRecordNum =new wxBoxSizer(wxHORIZONTAL);
    this->sbRecordNum=new wxSpinButton(parent,SB_RECORD_NUMBER_ID);
    this->tcRecordNum=new wxTextCtrl
            (this->parent,TC_RECORD_NUMBER_ID,wxString(""),wxPoint(-1,-1),wxSize(-1,-1),
             NULL,val);

    this->parent->Bind(wxEVT_SPIN_UP,&RecordNumberSpinCtrl::SpinUp,this);
    this->parent->Bind(wxEVT_SPIN_DOWN,&RecordNumberSpinCtrl::SpinDown,this);


    //Connect(wxEVT_SPIN_UP, wxSpinEventHandler(RecordNumberSpinCtrl::SpinUp()));
   // Connect(wxEVT_SPIN_DOWN, wxSpinEventHandler(RecordNumberSpinCtrl::SpinDown()));
    this->bsRecordNum->Add(this->tcRecordNum);
    this->bsRecordNum->Add(this->sbRecordNum);
}

wxBoxSizer* RecordNumberSpinCtrl::getBoxSizer()
{
    return this->bsRecordNum;

}

