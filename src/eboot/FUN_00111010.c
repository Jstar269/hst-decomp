/* HSTMATCH module=EBOOT.BIN start=0x00111010 end=0x00111044 symbol=FUN_00111010 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct GateObj {
  char pad00[0x88];
  u8 busy;          /* 0x88 set while FUN_001031e8 runs */
} GateObj;

extern GateObj *DAT_0034176c;
extern void FUN_001031e8();

/* Runs FUN_001031e8 with the global object's busy flag raised. */
void FUN_00111010(void)
{
  DAT_0034176c->busy = 1;
  FUN_001031e8();
  DAT_0034176c->busy = 0;
}
