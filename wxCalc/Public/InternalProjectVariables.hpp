#pragma once

#include <wx/wx.h>

namespace InternalProjectVariables
{
    extern wxString fontFaceName;
    extern int fontDisplaySmallSize;
    extern int fontDisplayLargeSize;
    extern wxFont fontButtons;
    extern wxBorder innerBorder;
    extern int displayDigitsMaxLength;

    enum Buttons {
        ZERO = 0,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        CALCULATE,
        PERCENT,
        POINT,
        PLUS_MINUS,
        BACKSPACE,
        CLEAR
    };
    
    // Buttons IDs
    constexpr int ID_BTN_ZERO         = 100 + Buttons::ZERO;
    constexpr int ID_BTN_ONE          = 100 + Buttons::ONE;
    constexpr int ID_BTN_TWO          = 100 + Buttons::TWO;
    constexpr int ID_BTN_THREE        = 100 + Buttons::THREE;
    constexpr int ID_BTN_FOUR         = 100 + Buttons::FOUR;
    constexpr int ID_BTN_FIVE         = 100 + Buttons::FIVE;
    constexpr int ID_BTN_SIX          = 100 + Buttons::SIX;
    constexpr int ID_BTN_SEVEN        = 100 + Buttons::SEVEN;
    constexpr int ID_BTN_EIGHT        = 100 + Buttons::EIGHT;
    constexpr int ID_BTN_NINE         = 100 + Buttons::NINE;
    constexpr int ID_BTN_PLUS         = 100 + Buttons::PLUS;
    constexpr int ID_BTN_MINUS        = 100 + Buttons::MINUS;
    constexpr int ID_BTN_MULTIPLY     = 100 + Buttons::MULTIPLY;
    constexpr int ID_BTN_DIVIDE       = 100 + Buttons::DIVIDE;
    constexpr int ID_BTN_CALCULATE    = 100 + Buttons::CALCULATE;
    constexpr int ID_BTN_PERCENT      = 100 + Buttons::PERCENT;
    constexpr int ID_BTN_POINT        = 100 + Buttons::POINT;
    constexpr int ID_BTN_PLUS_MINUS   = 100 + Buttons::PLUS_MINUS;
    constexpr int ID_BTN_BACKSPACE    = 100 + Buttons::BACKSPACE;
    constexpr int ID_BTN_CLEAR        = 100 + Buttons::CLEAR;
   
} //namespace InternalProjectVariables
