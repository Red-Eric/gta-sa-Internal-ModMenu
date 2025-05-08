#pragma once
#include <d3d9.h>

typedef HRESULT(__stdcall* endScene)(IDirect3DDevice9* pDevice);
extern endScene pEndScene;

void hookEndScene();
