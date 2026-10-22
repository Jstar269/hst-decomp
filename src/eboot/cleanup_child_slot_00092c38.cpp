/* HSTMATCH module=EBOOT.BIN start=0x00092c38 end=0x00092d10 symbol=FUN_00092c38 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined4 * FUN_0005d818(...);
extern void FUN_00092258(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_00092c38(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  iVar1 = (param_2 << 2) + param_1;
  piVar2 = *(int **)(iVar1 + 0x50);
  puVar4 = (undefined4 *)(iVar1 + 0x50);
  if (piVar2 != (int *)0x0) {
    if (piVar2 != (int *)0x0) {
      delete ((VC_0 *)(piVar2));
      *puVar4 = 0;
    }
    if ((param_2 == 0) && (*(int *)(param_1 + 0x70) != 0)) {
      FUN_0005d818(*(int *)(param_1 + 0x70),1);
      *(undefined4 *)(param_1 + 0x70) = 0;
    }
    if (param_2 == 2) {
      uVar3 = 0;
      iVar1 = param_1;
      do {
        uVar3 = uVar3 + 1;
        *(undefined4 *)(iVar1 + 4) = 0xffffffff;
        iVar1 = iVar1 + 4;
      } while (uVar3 < 7);
    }
    if (param_2 == 5) {
      *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
    }
    FUN_00092258(param_1);
  }
  return;
}
