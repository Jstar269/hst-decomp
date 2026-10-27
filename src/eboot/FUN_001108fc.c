/* HSTMATCH module=EBOOT.BIN start=0x001108fc end=0x00110a78 symbol=FUN_001108fc lang=c99 data=0x002d9264 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001108fc.c) corrected by hand: used float member copies, volatile flag rereads, and a shared post-cleanup object load; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002d9264-0x002d92b0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined DAT_002d9210;
extern undefined DAT_00307dd4;
extern int FUN_001026b8();
extern undefined4 * FUN_00102e38();
extern void FUN_00103480();
extern int FUN_001039d8();
extern void FUN_00104118();
extern void FUN_0010d4a8(int);

undefined4 * FUN_001108fc(undefined4 *param_1)
{
  int iVar1;
  
  FUN_00102e38(param_1);
  *param_1 = (unsigned int)(&DAT_00307dd4);
  param_1[0x15] = (unsigned int)(&DAT_002d9210);
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  FUN_00104118((int)param_1,(uint *)"data/menu/menu_common/info_messe_layout.lay",0);
  iVar1 = FUN_001039d8((int)param_1,(byte *)"messe",0);
  iVar1 = FUN_001026b8(iVar1,(byte *)"messe_text0");
  param_1[0x16] = *(undefined4 *)(iVar1 + 0x20);
  iVar1 = FUN_001039d8((int)param_1,(byte *)"messe",0);
  iVar1 = FUN_001026b8(iVar1,(byte *)"messe_text1");
  iVar1 = *(int *)(iVar1 + 0x20);
  param_1[0x17] = iVar1;
  *(float *)(iVar1 + 0x60) = *(float *)(param_1[0x16] + 0x60);
  *(float *)(param_1[0x17] + 100) = *(float *)(param_1[0x16] + 100);
  FUN_00103480((int)param_1);
  iVar1 = param_1[0x16];
  *(volatile unsigned char *)(iVar1 + 0x14c) = 1;
  if (*(volatile unsigned char *)(iVar1 + 0x14c) == 0) {
    FUN_0010d4a8(iVar1);
    iVar1 = param_1[0x17];
  }
  else {
    iVar1 = param_1[0x17];
  }
  *(volatile unsigned char *)(iVar1 + 0x14c) = 1;
  if (*(volatile unsigned char *)(iVar1 + 0x14c) == 0) {
    FUN_0010d4a8(iVar1);
  }
  iVar1 = param_1[0x16];
  iVar1 = param_1[0x16];
  *(undefined4 *)(iVar1 + 0x13c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x140) = 0;
  iVar1 = param_1[0x17];
  *(undefined4 *)(iVar1 + 0x13c) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x140) = 0;
  iVar1 = param_1[0x16];
  *(undefined **)(iVar1 + 0xf8) = &DAT_002d9210;
  *(undefined4 *)(iVar1 + 0x138) = 0;
  FUN_0010d4a8(iVar1);
  iVar1 = param_1[0x17];
  *(undefined **)(iVar1 + 0xf8) = &DAT_002d9210;
  *(undefined4 *)(iVar1 + 0x138) = 0;
  FUN_0010d4a8(iVar1);
  param_1[0x1b] = 0x43f00000;
  param_1[0x1c] = 0x43f00000;
  return param_1;
}
