#define NGS_SYSTEM_IS_ESP true
#define NGS_USE_HPP true
#include "ia/ia.h"
#include "ia/ia.hpp"
#include "ia/ia_main.hpp"

extern "C" void app_main(){
    ia_main();
}