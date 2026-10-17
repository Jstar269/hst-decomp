/* HSTMATCH module=EBOOT.BIN start=0x001d1f04 end=0x001d1f80 symbol=FUN_001d1f04 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5), refined by hstperm.py tag p4 random mutation from try/gen-a5/v17/FUN_001d1f04.cpp; exact match verified; names and types await human review. */
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
extern void FUN_000ffb3c(...);
extern void FUN_00103480(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001d1f04(int param_1)
{
  uint uVar2;
  int iVar1;
  
  uVar2 = 0;
  iVar1 = param_1;
  do {
    FUN_000ffb3c(*(undefined4 *)(iVar1 + 0x6c),0);
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 4;
  } while (uVar2 < 2);
  ((VC_0 *)(*(int **)(param_1 + 0x58)))->m((int)(0));
  *(undefined4 *)(**(int **)(param_1 + 4) + 0x60) = 0;
  FUN_00103480(param_1);
  return;
}
