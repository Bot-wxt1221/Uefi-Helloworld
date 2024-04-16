#ifndef H_BOOT
#define H_BOOT
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include "Video.h"

EFI_STATUS
EFIAPI
UefiMain(EFI_HANDLE IN ImageHandle,EFI_SYSTEM_TABLE IN *Systemtable);
#endif
