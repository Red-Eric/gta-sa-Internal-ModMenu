#include "func.h"

weaponN GetTestFuncFromAddress(void* addr) {
    return reinterpret_cast<weaponN>(addr);
}
