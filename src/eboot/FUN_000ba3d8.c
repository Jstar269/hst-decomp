/* HSTMATCH module=EBOOT.BIN start=0x000ba3d8 end=0x000ba48c symbol=FUN_000ba3d8 lang=c99 data=0x002d4b0c */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_000ba3d8.c) corrected by hand: passed the tested field to FUN_002b78e8, typed the variadic log helper, and reversed the result branch; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d4b0c-0x002d4b57) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined DAT_003073f0;
extern void FUN_00000a00();
extern void FUN_000ba3ac(const char *, ...);
extern void FUN_000bb780();
extern void FUN_000bb9d4();
extern void FUN_000bbf20();
extern void FUN_000bc524();
extern void FUN_000bc72c();
extern int FUN_002b78e8(int);

int * FUN_000ba3d8(int *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    *param_1 = (unsigned int)(&DAT_003073f0);
    FUN_000bc524();
    FUN_000bc72c(param_1);
    FUN_000bbf20(param_1);
    FUN_000bb780(param_1);
    FUN_000bb9d4(param_1);
    if (param_1[0xd] > 0) {
      iVar1 = FUN_002b78e8(param_1[0xd]);
      if (iVar1 != 0) {
        FUN_000ba3ac("sceKernelDeleteSema() failed. ret = 0x%x\n",iVar1);
      } else {
        FUN_000ba3ac("sceKernelDeleteSema() success\n");
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
