#pragma once

#include "wxCalcMain.hpp"
#include "MainWindow.hpp"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainWindow* mainWindow = new MainWindow(wxT("Calculator"));

    mainWindow->Show(true);

    return true;
}
