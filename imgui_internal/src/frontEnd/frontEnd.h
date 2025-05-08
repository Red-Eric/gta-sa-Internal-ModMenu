#pragma once
#include <d3d9.h>

namespace frontEnd {
    HRESULT Render(IDirect3DDevice9* pDevice, HRESULT(__stdcall* originalEndScene)(IDirect3DDevice9*));
}
