/* HSTMATCH module=hstp_trans_main.prx start=0x0020c850 end=0x0020c8ac symbol=FUN_0020c850 lang=c99 */
/* Clone of src/eboot/FUN_001fe080.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Context {
  char pad0[0x80];
  u32 flags;  /* 0x80 */
} Context;

extern Context *DAT_003751d4;
extern bool FUN_0001e6b0();

/* Result of the call is forced to 0 when any bit of blocked_mask is set in the context flags. */
u8 FUN_0020c850(u32 arg_a,u32 arg_b,u32 blocked_mask)
{
  u8 result;
  
  result = FUN_0001e6b0(DAT_003751d4,arg_a,arg_b,2,9);
  if ((DAT_003751d4->flags & blocked_mask) != 0) {
    result = 0;
  }
  return result;
}
