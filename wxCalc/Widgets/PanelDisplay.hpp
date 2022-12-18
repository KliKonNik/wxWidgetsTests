#pragma once

#include <wx/wx.h>

class PanelDisplay : public wxPanel
{
public:
    PanelDisplay(wxWindow* parent);

private:
    wxStaticText* _historyDisplayLine;
    wxStaticText* _workingDisplayLine;
};
