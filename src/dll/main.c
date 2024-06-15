// This DLL is for Task Manager, and it replaces the dxgi.dll. When the DllMain entry is called, it will open up a cmd prompt with administrator privileges.
#include <windows.h>
#include <stdbool.h>
#include <stdio.h>

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD fdwReason, LPVOID lpvReserved)
{

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            FreeConsole();
            system("cmd");
            break;
        case DLL_PROCESS_DETACH:
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
    }

    return TRUE;
}

void *ApplyCompatResolutionQuirking() { return NULL; }
void *CompatString() { return NULL; }
void *CompatValue() { return NULL; }
void *CreateDXGIFactory() { return NULL; }
void *CreateDXGIFactory1() { return NULL; }
void *CreateDXGIFactory2() { return NULL; }
void *DXGID3D10CreateDevice() { return NULL; }
void *DXGID3D10CreateLayeredDevice() { return NULL; }
void *DXGID3D10GetLayeredDeviceSize() { return NULL; }
void *DXGID3D10RegisterLayers() { return NULL; }
void *DXGIDeclareAdapterRemovalSupport() { return NULL; }
void *DXGIDisableVBlankVirtualization() { return NULL; }
void *DXGIDumpJournal() { return NULL; }
void *DXGIGetDebugInterface1() { return NULL; }
void *DXGIReportAdapterConfiguration() { return NULL; }
void *PIXBeginCapture() { return NULL; }
void *PIXEndCapture() { return NULL; }
void *PIXGetCaptureState() { return NULL; }
void *SetAppCompatStringPointer() { return NULL; }
void *UpdateHMDEmulationStatus() { return NULL; }
