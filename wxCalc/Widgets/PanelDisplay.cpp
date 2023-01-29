#include "PanelDisplay.hpp"
#include "Public/Colors.hpp"
#include "Public/InternalProjectVariables.hpp"

PanelDisplay::PanelDisplay(wxWindow* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
    SetBackgroundColour(Colors::WHITE);
    
    wxBoxSizer* bsVDisplay = new wxBoxSizer(wxVERTICAL);

    _historyDisplayLine = new wxStaticText(this, wxID_ANY, "");
    _historyDisplayLine->SetWindowStyleFlag(wxALIGN_RIGHT | wxST_NO_AUTORESIZE);
    
    wxFont fontHistoryLine;
    fontHistoryLine.SetFaceName(InternalProjectVariables::fontFaceName);
    fontHistoryLine.SetPointSize(InternalProjectVariables::fontDisplaySmallSize);
    
    _historyDisplayLine->SetFont(fontHistoryLine);

    _workingDisplayLine = new wxStaticText(this, wxID_ANY, "0");
    _workingDisplayLine->SetWindowStyleFlag(wxALIGN_RIGHT | wxST_NO_AUTORESIZE);

    wxFont fontWorkingLine{fontHistoryLine};
    fontWorkingLine.SetWeight(wxFONTWEIGHT_BOLD);
    fontWorkingLine.SetPointSize(InternalProjectVariables::fontDisplayLargeSize);

    _workingDisplayLine->SetFont(fontWorkingLine);

    bsVDisplay->Add(_historyDisplayLine, 1, wxEXPAND | wxRIGHT | wxLEFT | wxTOP, wxBorder(10));
    bsVDisplay->Add(_workingDisplayLine, 1, wxEXPAND | wxRIGHT | wxLEFT | wxBOTTOM, wxBorder(10));
    
    this->SetSizer(bsVDisplay);
}

const wxString PanelDisplay::GetHistory() const
{
    return _historyDisplayLine->GetLabelText();
}

void PanelDisplay::ToHistoryDisplay(const wxString& msg)
{
    _historyDisplayLine->SetLabel(msg);
}

const wxString PanelDisplay::GetWorkingDisplay() const
{
    return _workingDisplayLine->GetLabelText();
}

void PanelDisplay::ToWorkingDisplay(const wxString& msg)
{
    _workingDisplayLine->SetLabel(msg);
}
