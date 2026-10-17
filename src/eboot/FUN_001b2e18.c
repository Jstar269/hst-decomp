/* HSTMATCH module=EBOOT.BIN start=0x001b2e18 end=0x001b2e78 symbol=FUN_001b2e18 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_001b2e18.c; exact match verified; names and types await human review. */
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

extern int FUN_00062418();

void FUN_001b2e18(int *param_1)
{
  int iVar2;
  int iVar1;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0x2b0);
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 0x2b4);
  }
  else {
    if (iVar1 != 0) {
      FUN_00062418(iVar1,1);
      *(undefined4 *)(iVar2 + 0x2b0) = 0;
    }
  }
  if (((*(int *)(iVar2 + 0x2b4)) != 0) && ((*(int *)(iVar2 + 0x2b4)) != 0)) {
    FUN_00062418((*(int *)(iVar2 + 0x2b4)),1);
    *(undefined4 *)(iVar2 + 0x2b4) = 0;
  }
  return;
}
