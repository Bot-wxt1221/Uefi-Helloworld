#include "Boot.h"
EFI_STATUS
EFIAPI
UefiMain(EFI_HANDLE IN ImageHandle,EFI_SYSTEM_TABLE IN *Systemtable){
  Print(L"Hello World! Let Start edk2!\n");
  EFI_GRAPHICS_OUTPUT_BLT_PIXEL red={0,0,255,0};
  EFI_STATUS ret=EFI_SUCCESS;
  VideoInit(ImageHandle,&Gop);
  Gop->Blt(Gop,
           &red,
           EfiBltVideoFill,
           0,0,
           0,0,
           100,100,
           0
  );
  Gop->Blt(
    Gop,
    NULL,
    EfiBltVideoToVideo,
    0,0,
    200,200,
    100,100,
    0
  );
  EFI_FILE_PROTOCOL *Bin;
  ret=GetFileHandle(ImageHandle,
                    L"\\kernel.bin",
                    &Bin);
  if(EFI_ERROR(ret)){
    Print(L"Error");
    return ret;
  }
  EFI_PHYSICAL_ADDRESS BinA;
  ret=ReadFile(Bin,&BinA);
  if(EFI_ERROR(ret)){
    Print(L"Error");
    return ret;
  }
  asm("jmp %0"::"m"(BinA));
  return EFI_SUCCESS;
}
