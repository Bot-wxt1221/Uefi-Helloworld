#ifndef H_FILE
#define H_FILE
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

EFI_STATUS
EFIAPI
GetFileHandle(
  EFI_HANDLE IN ImageHandle,
  CHAR16 IN *Filename,
  EFI_FILE_PROTOCOL OUT **FileHandle,
);

EFI_STATUS
EFIAPI
GetFileHandle(
  EFI_FILE_PROTOCOL IN *FileHandle,
  EFI_PHYSICAL_ADDRESS OUT *File
);
#endif H_FILE
