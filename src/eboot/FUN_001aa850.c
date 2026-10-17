/* HSTMATCH module=EBOOT.BIN start=0x001aa850 end=0x001aa9a8 symbol=FUN_001aa850 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s512a); exact match verified; names and types await human review. */
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

extern undefined DAT_002e20d0;
extern void FUN_000ffb3c();
extern void FUN_0010d4a8();
extern undefined * FUN_001fea10();

void FUN_001aa850(undefined4 *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4, int param_5,int param_6,int param_7,int param_8,int iStackX_0)
{
  undefined4 uVar1;
  int iVar2;
  
  FUN_000ffb3c(*param_1,1);
  FUN_000ffb3c(*param_3,0);
  FUN_000ffb3c(*param_2,0);
  *(int *)(*param_2 + 0x24) = *(int *)(*param_2 + 0x28) + 0x11;
  uVar1 = (unsigned int)(FUN_001fea10(0x13,0,0));
  iVar2 = *(int *)(param_5 + 4);
  *(undefined4 *)(iVar2 + 0xf8) = uVar1;
  *(undefined4 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
  uVar1 = (unsigned int)(FUN_001fea10(0x13,0,0));
  iVar2 = *(int *)(param_6 + 4);
  *(undefined4 *)(iVar2 + 0xf8) = uVar1;
  *(undefined4 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
  iVar2 = *(int *)(param_7 + 4);
  *(undefined **)(iVar2 + 0xf8) = &DAT_002e20d0;
  *(undefined4 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
  uVar1 = (unsigned int)(FUN_001fea10(0x13,0,0));
  iVar2 = *(int *)(param_8 + 4);
  *(undefined4 *)(iVar2 + 0xf8) = uVar1;
  *(undefined4 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
  FUN_000ffb3c(*param_4,1);
  uVar1 = (unsigned int)(FUN_001fea10(0x13,0,0));
  iVar2 = *(int *)(iStackX_0 + 4);
  *(undefined4 *)(iVar2 + 0xf8) = uVar1;
  *(undefined4 *)(iVar2 + 0x138) = 1;
  FUN_0010d4a8();
  return;
}
