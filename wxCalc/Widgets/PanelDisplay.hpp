#pragma once

#include <wx/wx.h>

class PanelDisplay : public wxPanel
{
public:
    PanelDisplay(wxWindow* parent);

    const wxString GetHistory() const;
    void ToHistoryDisplay(const wxString& msg);
    const wxString GetWorkingDisplay() const;
    void ToWorkingDisplay(const wxString& msg);

private:
    wxStaticText* _historyDisplayLine;
    wxStaticText* _workingDisplayLine;
};
