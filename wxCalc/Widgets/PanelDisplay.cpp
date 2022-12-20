#include "PanelDisplay.hpp"
#include "PublicVars/Colors.hpp"
#include "PublicVars/InternalProjectVariables.hpp"

PanelDisplay::PanelDisplay(wxWindow* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
    SetBackgroundColour(Colors::WHITE);
    
    wxBoxSizer* bsVDisplay = new wxBoxSizer(wxVERTICAL);

    _historyDisplayLine = new wxStaticText(this, wxID_ANY, "_history line_0");
    _historyDisplayLine->SetWindowStyleFlag(wxALIGN_RIGHT);
    
    wxFont fontHistoryLine;
    fontHistoryLine.SetFaceName(InternalProjectVariables::fontFaceName);
    fontHistoryLine.SetPointSize(InternalProjectVariables::fontDisplaySmallSize);
    
    _historyDisplayLine->SetFont(fontHistoryLine);

    _workingDisplayLine = new wxStaticText(this, wxID_ANY, "_working line_0");
    _workingDisplayLine->SetWindowStyleFlag(wxALIGN_RIGHT);

    wxFont fontWorkingLine{fontHistoryLine};
    fontWorkingLine.SetWeight(wxFONTWEIGHT_BOLD);
    fontWorkingLine.SetPointSize(InternalProjectVariables::fontDisplayLargeSize);

    _workingDisplayLine->SetFont(fontWorkingLine);

    bsVDisplay->Add(_historyDisplayLine, 1, wxEXPAND | wxRIGHT | wxLEFT | wxTOP, wxBorder(10));
    bsVDisplay->Add(_workingDisplayLine, 1, wxEXPAND | wxRIGHT | wxLEFT | wxBOTTOM, wxBorder(10));
    
    this->SetSizer(bsVDisplay);
}
