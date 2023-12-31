// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

typedef void(*ProcessEvent_t)(struct UObject*, void*, void*);
ProcessEvent_t ProcessEvent_fn;
void ProcessEvent_f(struct UObject* object, UFunction* Function, void* Params)
{
    nlog("Function: [ %s ]\n", Function->GetFullName().c_str());

    ProcessEvent_fn(object, Function, Params);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        Present = Present_t(signature(Xors("48 89 5C 24 10 48 89 74 24 20 55 57 41 56 48 8D 6C 24 90 48 81 EC 70 01 00 00 48 8B 05 57 9E 0C 00 48 33 C4 48 89 45 60")).import(Xors("dxgi.dll")).GetPointer());

        DX12::hwnd = LI_FN(FindWindowA).safe()(Xors("UnrealWindow"), NULL);

        DX12::WndProc = (WNDPROC)SetWindowLongPtr(DX12::hwnd, GWLP_WNDPROC, (uint64_t)DX12::MainProc);

        //ProcessEvent_fn = (ProcessEvent_t)(UWorld::Singleton()->VFTable[0x4C]);

        GetViewPoint = GetViewPoint_t(signature(Xors("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 81 EC B0 00 00 00 0F 29 70 E8 48")).GetPointer());

        NamePoolData = (FNamePool*)(signature(Xors("48 8D 05 ? ? ? ? EB 13")).instruction(3).add(7).GetPointer());
        ObjObjects = (TUObjectArray*)(signature(Xors("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8D 04 D1 EB")).instruction(3).add(7).GetPointer());

        //DetourStart(ProcessEvent_fn, ProcessEvent_f);

        DetourStart(GetViewPoint, GetViewPoint_f);
        DetourStart(Present, DX12::Present_f);
    }

    return TRUE;
}