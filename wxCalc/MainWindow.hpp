#pragma once

#include <wx/wx.h>

#include "Widgets/PanelDisplay.hpp"
#include "Widgets/PanelButtons.hpp"
#include "Public/Operand.hpp"
#include "Public/Operator.hpp"

class MainWindow : public wxFrame
{
public:
    MainWindow(const wxString& title);

private:
    PanelDisplay*   _panelDisplay;
    PanelButtons*   _panelButtons;
    Operand         _operandPrevious;
    Operand         _operandCurrent;
    Operator        _operator;
    bool            _displayReaded;

    void ResetError();

    void OnButtonNumberClicked(wxCommandEvent& event);
    void OnButtonOperatorClicked(wxCommandEvent& event);
    void OnButtonCalculateClicked(wxCommandEvent& event);
    void OnButtonPercentClicked(wxCommandEvent& event);
    void OnButtonPointClicked(wxCommandEvent& event);
    void OnButtonPlusMinusClicked(wxCommandEvent& event);
    void OnButtonBackspaceClicked(wxCommandEvent& event);
    void OnButtonClearClicked(wxCommandEvent& event);

DECLARE_EVENT_TABLE()
};