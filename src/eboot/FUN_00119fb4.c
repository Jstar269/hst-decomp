/* HSTMATCH module=EBOOT.BIN start=0x00119fb4 end=0x0011a004 symbol=FUN_00119fb4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003386b0;

void FUN_00119fb4(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(DAT_003386b0 + 0xa0);
  *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + *(int *)(param_1 + 0xf4);
  *(int *)(iVar1 + 0x110) = *(int *)(iVar1 + 0x110) + *(int *)(param_1 + 0xf8);
  *(int *)(iVar1 + 0x16c) = *(int *)(iVar1 + 0x16c) + *(int *)(param_1 + 0xfc);
  *(int *)(iVar1 + 0x1c8) = *(int *)(iVar1 + 0x1c8) + *(int *)(param_1 + 0x100);
  return;
}
