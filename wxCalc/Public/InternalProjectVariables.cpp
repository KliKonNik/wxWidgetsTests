#include "InternalProjectVariables.hpp"

namespace InternalProjectVariables
{
    wxString fontFaceName{ wxT("Lucida Console") };
    int fontDisplaySmallSize{ 18 };
    int fontDisplayLargeSize{ 30 };
    wxFont fontButtons(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, fontFaceName);
    wxBorder innerBorder{ wxBorder(3) };
    extern int displayDigitsMaxLength{ 16 };

} //namespace InternalProjectVariables
