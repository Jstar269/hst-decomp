/* HSTMATCH module=EBOOT.BIN start=0x00280ff0 end=0x00281064 symbol=FUN_00280ff0 lang=c99 helpers=FUN_002803d8@0x002803d8-0x00280404 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/FUN_00280ff0.c, completed with its same-file static helper FUN_002803d8 defined in front of it and placed at its own retail address by helpers=); the field store moved in front of the FUN_002b7898 call; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 DAT_00338ac4;
extern char DAT_002fe91c[];
extern void FUN_000bd924(u32, void (*)(void));
static void FUN_002803d8(...)
{
}
extern void FUN_00280830(void *, int, int);
extern void FUN_002b7898(void *);
extern void FUN_002807d0(void);
void FUN_00280ff0(unsigned char *param_1, int param_2)
{
  if (param_1[0x2c00] != 0) {
    FUN_002803d8(DAT_002fe91c);
    return;
  }
  FUN_00280830(param_1, 3, 0);
  *(int *)(param_1 + 4) = param_2;
  FUN_002b7898(param_1 + 0x10);
  FUN_000bd924(DAT_00338ac4, FUN_002807d0);
}
