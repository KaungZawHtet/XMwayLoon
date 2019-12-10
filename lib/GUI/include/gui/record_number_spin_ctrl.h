#ifndef RECORD_NUMBER_SPIN_CTRL_H
#define RECORD_NUMBER_SPIN_CTRL_H
#include <wx/wx.h>
#include <wx/spinbutt.h>
class RecordNumberSpinCtrl
{
public:
    RecordNumberSpinCtrl(wxWindow* parent);
    wxBoxSizer* getBoxSizer();
    unsigned long value=0;

    wxWindow *parent;

    wxSpinButton *sbRecordNum;
    wxTextCtrl *tcRecordNum;
    wxBoxSizer *bsRecordNum;


    void SpinUp(wxSpinEvent& event);
    void SpinDown(wxSpinEvent& event);



};

#endif // RECORD_NUMBER_SPIN_CTRL_H
