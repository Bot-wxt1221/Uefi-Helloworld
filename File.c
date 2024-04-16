#include "File.h"

EFI_STATUS
EFIAPI
GetFileHandle(
  EFI_HANDLE IN ImageHandle,
  CHAR16 IN *Filename,
  EFI_FILE_PROTOCOL OUT **FileHandle,
){
  EFI_STATUS ret=EFI_SUCCESS;
  UINTN HandleCount=0;
  EFI_HANDLE *HandleBuffer;
  ret=gBS->LocateHandleBuffer(
    ByProtocol,
    &gEfiSimpleFileSystemProtocolGuid,
    NULL,
    &HandleCount,
    &HandleBuffer
  );
  if(EFI_ERROR(ret)){
    printf("Error Get File handle!");
    return ret;
  }
}

EFI_STATUS
EFIAPI
GetFileHandle(
  EFI_FILE_PROTOCOL IN *FileHandle,
  EFI_PHYSICAL_ADDRESS OUT *File
);
