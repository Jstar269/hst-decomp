/* HSTMATCH module=EBOOT.BIN start=0x000ba3d8 end=0x000ba48c symbol=FUN_000ba3d8 lang=c99 data=0x002d4b0c */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_000ba3d8.c) corrected by hand: passed the tested field to FUN_002b78e8, typed the variadic log helper, and reversed the result branch; readability pass; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d4b0c-0x002d4b57) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/adhoc_net.h"

extern u8 DAT_003073f0;
extern void FUN_00000a00();
extern void FUN_000ba3ac(const char *, ...);
extern void FUN_000bb780();
extern void FUN_000bb9d4();
extern void FUN_000bbf20();
extern void FUN_000bc524();
extern void FUN_000bc72c();
extern int FUN_002b78e8(int);

/* Deleting destructor: tears the service object down, releases its semaphore, frees it when the flag is positive. */
AdhocNet * FUN_000ba3d8(AdhocNet *self,short delete_flag)
{
  int result;
  
  if (self != 0) {
    self->vtable = &DAT_003073f0;
    FUN_000bc524();
    FUN_000bc72c(self);
    FUN_000bbf20(self);
    FUN_000bb780(self);
    FUN_000bb9d4(self);
    if (self->sema > 0) {
      result = FUN_002b78e8(self->sema);
      if (result != 0) {
        FUN_000ba3ac("sceKernelDeleteSema() failed. ret = 0x%x\n",result);
      } else {
        FUN_000ba3ac("sceKernelDeleteSema() success\n");
      }
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
