#ifndef H_VIDEO
#define H_VIDEO
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

EFI_STATUS
EFIAPI
VideoInit(EFI_HANDLE IN ImageHandle,EFI_GRAPHICS_OUTPUT_PROTOCOL OUT **Gop);

extern EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop;
#endif
