/* HSTMATCH module=EBOOT.BIN start=0x0010b368 end=0x0010b3cc symbol=FUN_0010b368 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0362_0010b368_m10.c); exact match verified; names and types await human review. */
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


void FUN_0010b368(int param_1,int param_2)
{
  uint uVar2;
  int iVar1;
  
  *(undefined4 *)(param_1 + 0xd0) = 0;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0x110);
    *(undefined4 *)(param_1 + 0xe0) = 0;
    *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0x124) + -1;
  }
  *(undefined1 *)(param_1 + 0xe8) = 0;
  *(undefined1 *)(param_1 + 0xe9) = 0;
  *(undefined1 *)(param_1 + 0xea) = 0;
  *(undefined2 *)(param_1 + 0xec) = 0;
  *(undefined2 *)(param_1 + 0xee) = 0;
  *(undefined2 *)(param_1 + 0x11c) = 0;
  *(undefined2 *)(param_1 + 0x11e) = 0;
  uVar2 = 0;
  iVar1 = param_1;
  do {
    uVar2 = uVar2 + 1;
    *(undefined4 *)(iVar1 + 0xf0) = 0;
    iVar1 = iVar1 + 4;
  } while (uVar2 < 8);
  *(undefined1 *)(param_1 + 300) = 1;
  return;
}
