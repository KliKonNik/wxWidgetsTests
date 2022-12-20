#include "MainWindow.hpp"
#include "Widgets/PanelDisplay.hpp"
#include "Widgets/PanelButtons.hpp"
#include "PublicVars/InternalProjectVariables.hpp"
#include "PublicVars/Colors.hpp"

#include <wx/file.h>

MainWindow::MainWindow(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxCAPTION | wxCLOSE_BOX | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER)
{
    if (wxFile::Exists(wxT("resources/img/main.ico")))
    {
        SetIcon(wxIcon(wxT("resources/img/main.ico"), wxBITMAP_TYPE_ICO));
    }
    else
    {

    }

    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);
    
    mainPanel->SetBackgroundColour(Colors::DARK_GRAY);

    wxBoxSizer* bsVMainPanel = new wxBoxSizer(wxVERTICAL);

    PanelDisplay* panelDisplay = new PanelDisplay(mainPanel);

    PanelButtons* panelButtons = new PanelButtons(mainPanel);

    bsVMainPanel->Add(panelDisplay, 1, wxEXPAND | wxALL, InternalProjectVariables::innerBorder);
    bsVMainPanel->Add(panelButtons, 3, wxEXPAND | wxALL, InternalProjectVariables::innerBorder);
    
    mainPanel->SetSizerAndFit(bsVMainPanel);
    
    wxSize mainWindowMinSize{ wxSize(wxGetDisplaySize().GetX() / 4, wxGetDisplaySize().GetY() / 3) };

    SetSizeHints(mainWindowMinSize);

    Centre();
}