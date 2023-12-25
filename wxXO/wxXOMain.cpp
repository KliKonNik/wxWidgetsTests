#pragma once

#include "wxXOMain.hpp"
#include "MainWindow.hpp"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainWindow* mainWindow = new MainWindow(wxT("wxXO"));

    mainWindow->Show(true);

    return true;
}
