#include "MainWindow.hpp"
#include "Widgets/PanelDisplay.hpp"
#include "Widgets/PanelButtons.hpp"

MainWindow::MainWindow(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxCAPTION | wxCLOSE_BOX | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER)
{

    SetIcon(wxIcon(wxT("wxCalc/resources/img/calc_128.ico"), wxBITMAP_TYPE_ICO));

    wxPanel* mainPanel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* bsVMainPanel = new wxBoxSizer(wxVERTICAL);

    PanelDisplay* panelDisplay = new PanelDisplay(mainPanel);

    PanelButtons* panelButtons = new PanelButtons(mainPanel);

    bsVMainPanel->Add(panelDisplay, 0, wxEXPAND);
    bsVMainPanel->Add(panelButtons, 1, wxEXPAND | wxALL);
    
    mainPanel->SetSizerAndFit(bsVMainPanel);

    SetSizeHints(wxSize(wxGetDisplaySize().GetX() / 4, wxGetDisplaySize().GetY() / 3));

    Centre();
}