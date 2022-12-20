#include "InternalProjectVariables.hpp"

namespace InternalProjectVariables
{
    wxString fontFaceName{ wxT("Arial") };
    int fontDisplaySmallSize{ 18 };
    int fontDisplayLargeSize{ 24 };
    wxFont fontButtons(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, fontFaceName);
    wxBorder innerBorder{wxBorder(3)};

} //namespace Consts
