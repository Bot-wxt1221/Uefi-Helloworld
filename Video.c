#include "Video.h"

extern EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop;

EFI_STATUS
EFIAPI
VideoInit(EFI_HANDLE IN ImageHandle,EFI_GRAPHICS_OUTPUT_PROTOCOL OUT **Gop){
  EFI_STATUS ret=EFI_SUCCESS;
  UINTN NoHandles=0;
  EFI_HANDLE *buffer=NULL;
  ret=gBS->LocateHandleBuffer(ByProtocol,&gEfiGraphicsOutputProtocolGuid,NULL,&NoHandles,&buffer);
  if(EFI_ERROR(ret)){
    Print(L"Error while get Handle buffer");
  }
  Print(L"ret %d\n",ret);
  Print(L"HandlesNumbers %d\n",NoHandles);
  ret=gBS->OpenProtocol(buffer[0],
                        &gEfiGraphicsOutputProtocolGuid,
                        (void **)Gop,
                        ImageHandle,
                        NULL,
                        EFI_OPEN_PROTOCOL_GET_PROTOCOL);
  Print(L"ret %d\n",ret);
  if(EFI_ERROR(ret)){
    Print(L"Error %d",ret);
    return ret;
  }
  UINTN SizeofInfo=0;
  int used_graphics=-1;
  EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *info;
  for(int i=0;i<(*Gop)->Mode->MaxMode;i++){
    ret=(*Gop)->QueryMode(*Gop,i,&SizeofInfo,&info);
    if(EFI_ERROR(ret)){
      Print(L"Failed while quering mode.\n");
      return ret;
    }
    Print(L"Mode %d, %d * %d\n",i,info->HorizontalResolution,info->VerticalResolution);
    if(info->HorizontalResolution==1600){
      used_graphics=i;
    }
  }
  if(used_graphics!=-1){
    ret=(*Gop)->SetMode(*Gop,used_graphics);
    if(EFI_ERROR(ret)){
      Print(L"Error %d",ret);
    }
  }else{
    Print(L"Not Found!");
  }
  return EFI_SUCCESS;
}

