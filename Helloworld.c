#include <Uefi.h>
#include <Library/UefiLib.h>

EFI_STATUS
EFIAPI
UefiMain(EFI_HANDLE IN ImageHandle,EFI_SYSTEM_TABLE IN *Systemtable){
  Print(L"Hello World! Let Start edk2!\n");
  return EFI_SUCCESS;
}
