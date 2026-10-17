/* HSTMATCH module=EBOOT.BIN start=0x0018a960 end=0x0018a9fc symbol=FUN_0018a960 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2), refined by hstperm.py tag p4 random mutation from try/gen-a2/v0/FUN_0018a960.c; exact match verified; names and types await human review. */
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

extern uint * FUN_000114c0();
extern void FUN_0010d4a8();
extern void FUN_0018a9fc();

void FUN_0018a960(int param_1,undefined4 param_2,int param_3)
{
  int iVar3;
  int iVar2;
  int iVar1;
  
  if (param_3 != 0) {
    FUN_0018a9fc(param_1);
  }
  *(undefined4 *)(param_1 + 0x98) = param_2;
  iVar3 = 0;
  iVar2 = param_1;
  do {
    FUN_000114c0((uint *)(iVar2 + 0x9c),0,0x400);
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0x400;
  } while (3 > iVar3);
  iVar3 = 0;
  iVar2 = param_1;
  do {
    iVar1 = *(int *)(param_1 + 0x7c);
    *(int *)(iVar1 + 0xf8) = iVar2 + 0x9c;
    *(undefined4 *)(iVar1 + 0x138) = 0;
    FUN_0010d4a8(iVar1);
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 4;
    iVar2 = iVar2 + 0x400;
  } while (iVar3 < 2);
  return;
}
