#include "MainWindow.hpp"
#include "Public/InternalProjectVariables.hpp"
#include "Public/Colors.hpp"
#include "Public/Utils.hpp"

#include <wx/file.h>

// for ID_BTN_* and others
using namespace InternalProjectVariables;

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_BUTTON(ID_BTN_ZERO,         MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_ONE,          MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_TWO,          MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_THREE,        MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_FOUR,         MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_FIVE,         MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_SIX,          MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_SEVEN,        MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_EIGHT,        MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_NINE,         MainWindow::OnButtonNumberClicked)
    EVT_BUTTON(ID_BTN_PLUS,         MainWindow::OnButtonOperatorClicked)
    EVT_BUTTON(ID_BTN_MINUS,        MainWindow::OnButtonOperatorClicked)
    EVT_BUTTON(ID_BTN_MULTIPLY,     MainWindow::OnButtonOperatorClicked)
    EVT_BUTTON(ID_BTN_DIVIDE,       MainWindow::OnButtonOperatorClicked)
    EVT_BUTTON(ID_BTN_CALCULATE,    MainWindow::OnButtonCalculateClicked)
    EVT_BUTTON(ID_BTN_PERCENT,      MainWindow::OnButtonPercentClicked)
    //EVT_BUTTON(ID_BTN_POINT,        MainWindow::OnButtonPointClicked) // why is it commented? See line 68
    EVT_BUTTON(ID_BTN_PLUS_MINUS,   MainWindow::OnButtonPlusMinusClicked)
    //EVT_BUTTON(ID_BTN_BACKSPACE,    MainWindow::OnButtonBackspaceClicked) // why is it commented? See line 68
    EVT_BUTTON(ID_BTN_CLEAR,        MainWindow::OnButtonClearClicked)
wxEND_EVENT_TABLE()

MainWindow::MainWindow(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title)
    , _displayReaded(false)
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

    _panelDisplay = new PanelDisplay(mainPanel);

    _panelButtons = new PanelButtons(mainPanel);

    bsVMainPanel->Add(_panelDisplay, 1, wxEXPAND | wxALL, InternalProjectVariables::innerBorder);
    bsVMainPanel->Add(_panelButtons, 4, wxEXPAND | wxALL, InternalProjectVariables::innerBorder);
    
    mainPanel->SetSizerAndFit(bsVMainPanel);
    
    wxSize mainWindowMinSize{ wxSize(wxGetDisplaySize().GetX() / 3, wxGetDisplaySize().GetY() / 3) };

    SetSizeHints(mainWindowMinSize);

    Centre();

    //these cases are presented for educational purposes only
    Connect(ID_BTN_BACKSPACE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainWindow::OnButtonBackspaceClicked));
    _panelButtons->GetButtons()[Buttons::POINT]->Bind(wxEVT_BUTTON, &MainWindow::OnButtonPointClicked, this);
}

void MainWindow::ResetError()
{
    if (Utils::DigitCount(_panelDisplay->GetWorkingDisplay().ToStdString()) == 0)
    {
        _panelDisplay->ToWorkingDisplay('0');
        _displayReaded = false;
    }
}

void MainWindow::OnButtonNumberClicked(wxCommandEvent& event)
{
    std::string lineToDisp;

    if (_displayReaded)
    {
        _panelDisplay->ToWorkingDisplay('0');
        _displayReaded = false;
    }

    if (_panelDisplay->GetWorkingDisplay() != '0')
    {
        lineToDisp = _panelDisplay->GetWorkingDisplay();
    }

    if (Utils::DigitCount(lineToDisp) < displayDigitsMaxLength)
    {
        char currentNumber = '0' + Utils::WhatNumberPressed(event.GetId());

        lineToDisp = Utils::Despacer(lineToDisp);

        lineToDisp += currentNumber;

        lineToDisp = Utils::StringSeparator(lineToDisp);
    }
    
    _panelDisplay->ToWorkingDisplay(lineToDisp);
}

void MainWindow::OnButtonOperatorClicked(wxCommandEvent& event)
{
    std::string lineToHistory;
    
    ResetError();

    _operandPrevious.SetValueFromString(_panelDisplay->GetWorkingDisplay().ToStdString());
    _operandCurrent.SetEmpty(true);
    _operator.Set(Utils::WhatOperatorPressed(event.GetId()));
    
    lineToHistory = _operandPrevious.GetString() + ' ' + _operator.GetChar();

    _panelDisplay->ToHistoryDisplay(lineToHistory);
    _displayReaded = true;
}

void MainWindow::OnButtonCalculateClicked(wxCommandEvent& event)
{
    std::string lineToHistory;

    ResetError();

    if (!_operator.IsEmpty())
    {
        if (!_operandPrevious.IsEmpty() && _operandCurrent.IsEmpty())
        {
            _operandCurrent.SetValueFromString(_panelDisplay->GetWorkingDisplay().ToStdString());
        }
        else
        {
            _operandPrevious.SetValueFromString(_panelDisplay->GetWorkingDisplay().ToStdString());
        }

        lineToHistory = _operandPrevious.GetString() + ' ' + _operator.GetChar() + ' ' + _operandCurrent.GetString() + ' ' + '=';
        _panelDisplay->ToHistoryDisplay(lineToHistory);

        Operand result = Utils::Calculate(_operandPrevious, _operator, _operandCurrent);

        if (!result.IsEmpty())
        {
            _panelDisplay->ToWorkingDisplay(result.GetString());
        }
        else
        {
            _panelDisplay->ToWorkingDisplay("Error");
        }
        _displayReaded = true;
    }
    else
    {
        _operandPrevious.SetValueFromString(_panelDisplay->GetWorkingDisplay().ToStdString());
        lineToHistory = _operandPrevious.GetString() + ' ' + '=';
        _panelDisplay->ToHistoryDisplay(lineToHistory);
        _displayReaded = true;
    }
}

void MainWindow::OnButtonPercentClicked(wxCommandEvent& event)
{
    ResetError();
    _operandCurrent.SetValueFromString(_panelDisplay->GetWorkingDisplay().ToStdString());
    _operandCurrent.SetValue(_operandCurrent.GetValue() / 100);
    _panelDisplay->ToWorkingDisplay(_operandCurrent.GetString());
    _operandCurrent.SetEmpty(true);
    _operandPrevious.SetEmpty(true);
}

void MainWindow::OnButtonPointClicked(wxCommandEvent& event)
{
    ResetError();

    std::string lineToDisp;
    lineToDisp = _panelDisplay->GetWorkingDisplay();

    if (std::find_if(lineToDisp.begin(), lineToDisp.end(), [](char c) { return c == '.'; }) == lineToDisp.end())
    {
        lineToDisp += '.';
        _panelDisplay->ToWorkingDisplay(lineToDisp);
    }
}

void MainWindow::OnButtonPlusMinusClicked(wxCommandEvent& event)
{
    ResetError();

    std::string lineToDisp{ _panelDisplay->GetWorkingDisplay() };

    if (lineToDisp[0] != '0')
    {
        if (lineToDisp[0] != '-')
        {
            lineToDisp = '-' + _panelDisplay->GetWorkingDisplay();
        }
        else
        {
            lineToDisp = _panelDisplay->GetWorkingDisplay().substr(1);
        }
    }
    _panelDisplay->ToWorkingDisplay(lineToDisp);

    _displayReaded = false;
}

void MainWindow::OnButtonBackspaceClicked(wxCommandEvent& event)
{
    std::string lineToDisp;
    lineToDisp = _panelDisplay->GetWorkingDisplay();

    lineToDisp = Utils::Despacer(lineToDisp);

    lineToDisp.erase(lineToDisp.size() - 1);

    if (lineToDisp.empty() || (Utils::DigitCount(lineToDisp) == 0))
    {
        lineToDisp = '0';
    }

    lineToDisp = Utils::StringSeparator(lineToDisp);

    _panelDisplay->ToWorkingDisplay(lineToDisp);
}

void MainWindow::OnButtonClearClicked(wxCommandEvent& event)
{
    _operandCurrent.SetEmpty(true);
    _operandPrevious.SetEmpty(true);
    _operator.Clear();
    _panelDisplay->ToHistoryDisplay("");
    _panelDisplay->ToWorkingDisplay('0');
    _displayReaded = false;
}
