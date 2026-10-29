/* HSTMATCH module=EBOOT.BIN start=0x001fe080 end=0x001fe0dc symbol=FUN_001fe080 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Context {
  char pad0[0x80];
  u32 flags;  /* 0x80 */
} Context;

extern Context *DAT_002cfc8c;
extern bool FUN_0001ea64();

/* Result of the call is forced to 0 when any bit of blocked_mask is set in the context flags. */
u8 FUN_001fe080(u32 arg_a,u32 arg_b,u32 blocked_mask)
{
  u8 result;
  
  result = FUN_0001ea64(DAT_002cfc8c,arg_a,arg_b,2,9);
  if ((DAT_002cfc8c->flags & blocked_mask) != 0) {
    result = 0;
  }
  return result;
}
