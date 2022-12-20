#include "PanelButtons.hpp"
#include "PublicVars/InternalProjectVariables.hpp"
#include "PublicVars/Colors.hpp"

PanelButtons::PanelButtons(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetBackgroundColour(parent->GetBackgroundColour());

    using InternalProjectVariables::Buttons;
    _buttons[Buttons::ZERO]       = new wxButton(this, InternalProjectVariables::ID_BTN_ZERO,       wxT("0"));
    _buttons[Buttons::ONE]        = new wxButton(this, InternalProjectVariables::ID_BTN_ONE,        wxT("1"));
    _buttons[Buttons::TWO]        = new wxButton(this, InternalProjectVariables::ID_BTN_TWO,        wxT("2"));
    _buttons[Buttons::THREE]      = new wxButton(this, InternalProjectVariables::ID_BTN_THREE,      wxT("3"));
    _buttons[Buttons::FOUR]       = new wxButton(this, InternalProjectVariables::ID_BTN_FOUR,       wxT("4"));
    _buttons[Buttons::FIVE]       = new wxButton(this, InternalProjectVariables::ID_BTN_FIVE,       wxT("5"));
    _buttons[Buttons::SIX]        = new wxButton(this, InternalProjectVariables::ID_BTN_SIX,        wxT("6"));
    _buttons[Buttons::SEVEN]      = new wxButton(this, InternalProjectVariables::ID_BTN_SEVEN,      wxT("7"));
    _buttons[Buttons::EIGHT]      = new wxButton(this, InternalProjectVariables::ID_BTN_EIGHT,      wxT("8"));
    _buttons[Buttons::NINE]       = new wxButton(this, InternalProjectVariables::ID_BTN_NINE,       wxT("9"));
    _buttons[Buttons::PLUS]       = new wxButton(this, InternalProjectVariables::ID_BTN_PLUS,       wxT("+"));
    _buttons[Buttons::MINUS]      = new wxButton(this, InternalProjectVariables::ID_BTN_MINUS,      wxT("-"));
    _buttons[Buttons::DIVIDE]     = new wxButton(this, InternalProjectVariables::ID_BTN_DIVIDE,     wxT("/"));
    _buttons[Buttons::MULTIPLY]   = new wxButton(this, InternalProjectVariables::ID_BTN_MULTIPLY,   wxT("*"));
    _buttons[Buttons::CALCULATE]  = new wxButton(this, InternalProjectVariables::ID_BTN_CALCULATE,  wxT("="));
    _buttons[Buttons::PERCENT]    = new wxButton(this, InternalProjectVariables::ID_BTN_PERCENT,    wxT("%"));
    _buttons[Buttons::POINT]      = new wxButton(this, InternalProjectVariables::ID_BTN_POINT,      wxT("."));
    _buttons[Buttons::PLUS_MINUS] = new wxButton(this, InternalProjectVariables::ID_BTN_PLUS_MINUS, wxT("±"));
    _buttons[Buttons::BACKSPACE]  = new wxButton(this, InternalProjectVariables::ID_BTN_BACKSPACE,  wxT("←"));
    _buttons[Buttons::CLEAR]      = new wxButton(this, InternalProjectVariables::ID_BTN_CLEAR,      wxT("C"));

    for (int i = Buttons::ZERO /*0*/; i <= Buttons::CLEAR /*19*/; ++i)
    {
        _buttons[i]->SetFont(InternalProjectVariables::fontButtons);

        if (i >= Buttons::ZERO && i <= Buttons::NINE)
        {
            _buttons[i]->SetOwnBackgroundColour(Colors::LIGHT_GRAY);
        }

        if (i >= Buttons::PLUS && i <= Buttons::CALCULATE)
        {
            _buttons[i]->SetOwnBackgroundColour(Colors::LIGHT_ORANGE);
        }

        if (i >= Buttons::PERCENT && i <= Buttons::CLEAR)
        {
            _buttons[i]->SetOwnBackgroundColour(Colors::GRAY);
        }
    }

    wxBoxSizer* bsButtons = new wxBoxSizer(wxVERTICAL);

    wxGridSizer* gsButtons = new wxGridSizer(5, 4, 0, 0);

    gsButtons->Add(_buttons[Buttons::CLEAR],        1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::BACKSPACE],    1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::PERCENT],      1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::PLUS],         1, wxEXPAND);

    gsButtons->Add(_buttons[Buttons::SEVEN],        1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::EIGHT],        1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::NINE],         1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::MINUS],        1, wxEXPAND);

    gsButtons->Add(_buttons[Buttons::FOUR],         1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::FIVE],         1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::SIX],          1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::MULTIPLY],     1, wxEXPAND);

    gsButtons->Add(_buttons[Buttons::ONE],          1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::TWO],          1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::THREE],        1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::DIVIDE],       1, wxEXPAND);

    gsButtons->Add(_buttons[Buttons::PLUS_MINUS],   1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::ZERO],         1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::POINT],        1, wxEXPAND);
    gsButtons->Add(_buttons[Buttons::CALCULATE],    1, wxEXPAND);

    bsButtons->Add(gsButtons, 1, wxEXPAND);

    this->SetSizer(bsButtons);
}
