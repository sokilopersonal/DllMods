#include "Device.h"
#include "Direct3D9.h"
#include "Texture.h"

#include "../GenerationsD3D9Ex/MemoryHandler.h"

HOOK(void, __cdecl, LoadPictureData, 0x743DE0,
    hh::mr::CPictureData* pPictureData, const uint8_t* pData, size_t length, hh::mr::CRenderingInfrastructure* pRenderingInfrastructure)
{
    if (pPictureData->m_Flags & hh::db::eDatabaseDataFlags_IsMadeOne)
        return;

    const ComPtr<Device> device = (Device*)pRenderingInfrastructure->m_RenderingDevice.m_pD3DDevice;

    ComPtr<ID3D11Resource> texture;
    ComPtr<ID3D11ShaderResourceView> srv;

    HRESULT hr;
    {
        const auto lock = device->lock();

        hr = DirectX::CreateDDSTextureFromMemory(device->getDevice(), device->getDeviceContext(),
            pData, length, texture.GetAddressOf(), srv.GetAddressOf());
    }

    if (SUCCEEDED(hr))
    {
        pPictureData->m_pD3DTexture = (DX_PATCH::IDirect3DBaseTexture9*)(new Texture(device.Get(), texture.Get(), srv.Get()));
        pPictureData->m_Type = hh::mr::ePictureType_Texture;
    }
    else
    {
        pPictureData->m_pD3DTexture = nullptr;
        pPictureData->m_Type = hh::mr::ePictureType_Invalid;
    }

    pPictureData->m_Flags |= hh::db::eDatabaseDataFlags_IsMadeOne;
}

HOOK(HRESULT, __stdcall, FillTexture, 0xA55270, Texture* texture, void* function, void* data)
{
    return S_OK;
}

HOOK(Direct3D9*, __cdecl, Direct3DCreate, 0xA5EDD0, UINT SDKVersion)
{
    return new Direct3D9(SDKVersion);
}

HOOK(void, WINAPI, MyOutputDebugStringA, &OutputDebugStringA, LPCSTR lpOutputString)
{
    printf(lpOutputString);
}

extern "C" __declspec(dllexport) void Init()
{
    MemoryHandler::applyPatches();

    INSTALL_HOOK(LoadPictureData);
    INSTALL_HOOK(FillTexture);
    INSTALL_HOOK(Direct3DCreate);

    // Prevent half-pixel correction
    WRITE_MEMORY(0x64F4C7, uintptr_t, 0x15C5858); // MTFx
    WRITE_MEMORY(0x7866E2, uintptr_t, 0x15C5858); // FxPipeline

    // Ignore Devil's Details' fullscreen shader
    WRITE_CALL(0x64CF9E, 0x64F470);

    // Ignore SFD playback
    WRITE_MEMORY(0x7F2630, uint8_t, 0xC3);

#if _DEBUG
    INSTALL_HOOK(MyOutputDebugStringA);

    if (!GetConsoleWindow())
        AllocConsole();

    freopen("CONOUT$", "w", stdout);

    WRITE_MEMORY(0xE7B8F7, uint8_t, 0x00);
#endif
}