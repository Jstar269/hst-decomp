/* HSTMATCH module=EBOOT.BIN start=0x00150b6c end=0x00150c1c symbol=FUN_00150b6c lang=c99 data=0x002dc424 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00150b6c.c) corrected by hand: typed the global byte and helper arguments, and reused one materialized resource flag across logging; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc424-0x002dc42d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002dc440;
extern unsigned char DAT_003402f0;
extern void *DAT_0034a114;
extern char DAT_002dc430[];
extern int *FUN_0014c384(u32, int);
extern void FUN_0014d044(u32 *);
extern void FUN_0014fd94(char *, char *);
extern void FUN_001cc988(void *, int);

u32 FUN_00150b6c(u32 param_1,u32 *param_2)
{
  u32 key = *param_2;
  int value = *FUN_0014c384(key,0xb);
  int has_resource = value != 0;
  char *message;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    if (has_resource) {
      message = DAT_002dc430;
    }
    else {
      message = (char *)(&DAT_002dc440);
    }
    FUN_0014fd94("Match%s\n",message);
  }
  FUN_001cc988(DAT_0034a114,has_resource);
  *(u8 *)(param_2[3] + 0x5a) = 1;
  *FUN_0014c384(key,0xb) = 0;
  return 0;
}
