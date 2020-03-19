//
// Created by Kaung Zaw Htet on 2020-01-29.
//

#include <gui/type_extension/read_me_dialog.h>
#include <gui/type_extension/read_me_panel.h>

ReadMeDialog::ReadMeDialog(const wxString & title)
: wxDialog(NULL,-1,title,wxDefaultPosition,wxSize(600,470))

{
  this->pnlReadMe= new ReadMePanel(this);
    Centre();
    ShowModal();

    Destroy();

}