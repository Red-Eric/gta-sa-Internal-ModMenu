#include "mem.h"

uintptr_t getPointerAddress(uintptr_t ptr, std::vector<uintptr_t>Offsets) {

	uintptr_t addrs = ptr;
	for (int i = 0; i < Offsets.size(); i++) {
		addrs = *(uintptr_t*)addrs;
		addrs += Offsets[i];
	}
	return addrs;
}
