#pragma once

#include <wx/wx.h>

class PanelButtons : public wxPanel
{
public:
    PanelButtons(wxWindow* parent);
    
    // special for Bind()
    wxButton** GetButtons();

private:
    wxButton* _buttons[20];
};
