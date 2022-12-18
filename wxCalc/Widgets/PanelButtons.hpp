#pragma once

#include <wx/wx.h>

class PanelButtons : public wxPanel
{
public:
    PanelButtons(wxWindow* parent);
private:
    wxButton* _buttons[20];
};
