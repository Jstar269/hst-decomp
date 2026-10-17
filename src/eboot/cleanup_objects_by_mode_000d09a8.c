/* HSTMATCH module=EBOOT.BIN start=0x000d09a8 end=0x000d0a9c symbol=FUN_000d09a8 lang=c99 */
/* Clone of src/sharing_main/cleanup_objects_by_mode_000d45a4.c (hstclone.py tag u6cr5e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: rebuilt the mode ladder as a switch and typed the float cleanup argument; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_00058fc0(void *, int);
extern void FUN_0005f110(void *, float);

undefined4 FUN_000d09a8(int param_1,int param_2)
{
  unsigned char cVar1;
  int iVar2;
  
  switch (param_2) {
  case 0:
  case 1:
    break;
  case 0x16:
  case 0xe:
  case 8:
  case 0xc:
  case 9:
  case 10:
    iVar2 = *(int *)(param_1 + 0x3c);
    if (iVar2 != 0) {
      FUN_00058fc0((void *)iVar2,-1);
      FUN_0005f110((void *)iVar2,0.0f);
      *(undefined4 *)(iVar2 + 0xd0) = 0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    cVar1 = *(unsigned char *)(param_1 + 0xb0);
    if (cVar1 != 0) {
      iVar2 = *(int *)(param_1 + 0x9c);
      FUN_00058fc0((void *)iVar2,-1);
      FUN_0005f110((void *)iVar2,0.0f);
      *(undefined4 *)(iVar2 + 0xd0) = 0;
      *(undefined1 *)(param_1 + 0xb0) = 0;
    }
    break;
  case 0xb:
    break;
  default:
    break;
  }
  return 0;
}
