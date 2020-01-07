#include <gui/app.h>
#include <gui/main_frame.h>

bool App::OnInit()
{
    MainFrame *mainFrame=new MainFrame();
    mainFrame->Show();

    return true;
}
