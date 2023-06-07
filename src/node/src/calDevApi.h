#include "dllhelper.hpp"
#include <windows.h>
#include <shlwapi.h>
#include "CalDevLib.h"

class CalDevApi {
  DllHelper _dll{L"CalDevLib.dll"};

public:
  decltype(CalDev_init) *init = _dll["CalDev_init"];
  decltype(CalDev_hi) *hi = _dll["CalDev_hi"];
};

