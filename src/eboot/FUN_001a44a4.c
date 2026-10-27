/* HSTMATCH module=EBOOT.BIN start=0x001a44a4 end=0x001a452c symbol=FUN_001a44a4 lang=c99 data=0x002e1cfc */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q4); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e1cfc-0x002e1d0d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef int bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_0016baa0();
extern int FUN_0019ee24();
extern int FUN_001a4334();

void FUN_001a44a4(int param_1)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = **(int **)(*(int *)(param_1 + 900) + *(int *)(param_1 + 0x300) * 4);
  bVar1 = iVar2 == -1;
  if (bVar1) {
    uVar3 = FUN_001a4334();
    iVar2 = FUN_0019ee24("RandomSinpan=%d\n",uVar3);
  }
  FUN_0016baa0(iVar2,bVar1);
  *(undefined4 *)(param_1 + 0x308) = *(undefined4 *)(param_1 + 0x2fc);
  *(undefined4 *)(param_1 + 0x30c) = *(undefined4 *)(param_1 + 0x300);
  *(undefined4 *)(param_1 + 0x310) = *(undefined4 *)(param_1 + 0x304);
  return;
}
