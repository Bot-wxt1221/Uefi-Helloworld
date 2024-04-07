#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
EFI_STATUS
EFIAPI
UefiMain(EFI_HANDLE IN ImageHandle,EFI_SYSTEM_TABLE IN *Systemtable){
  Print(L"Hello World! Let Start edk2!\n");
  EFI_STATUS ret=EFI_SUCCESS;
  UINTN NoHandles=0;
  EFI_HANDLE *buffer=NULL;
  ret=gBS->LocateHandleBuffer(ByProtocol,&gEfiGraphicsOutputProtocolGuid,NULL,&NoHandles,&buffer);
  if(EFI_ERROR(ret)){
    Print(L"Error while get Handle buffer");
  }
  Print(L"ret %d\n",ret);
  Print(L"HandlesNumbers %d\n",NoHandles);
  EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop;
  ret=gBS->OpenProtocol(buffer[0],&gEfiGraphicsOutputProtocolGuid,(void **)&Gop,ImageHandle,NULL,EFI_OPEN_PROTOCOL_GET_PROTOCOL);
  Print(L"ret %d\n",ret);
  if(EFI_ERROR(ret)){
    Print(L"Error %d",ret);
  }
  return EFI_SUCCESS;
}
