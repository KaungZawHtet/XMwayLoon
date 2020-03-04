//
// Created by Kaung Zaw Htet on 2020-01-29.
//

#include <gui/data_generation/read_me_dialog.h>
#include <gui/data_generation/read_me_panel.h>

DataGenerationReadMeDialog::DataGenerationReadMeDialog(const wxString & title)
: wxDialog(NULL,-1,title,wxDefaultPosition,wxSize(600,600))

{
  this->pnlReadMe= new DataGenerationReadMePanel(this);
    Centre();
    ShowModal();

    Destroy();

}