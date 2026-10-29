/* HSTMATCH module=hstp_trans_main.prx start=0x002a2988 end=0x002a29a0 symbol=FUN_002a2988 lang=c99 */
/* Clone of src/eboot/FUN_00291280.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f3b40;
extern u32 DAT_003f3b44;

/* Stores a pair of values (the caller passes the same value twice) in globals; always returns 1. */
u32 FUN_002a2988(u32 unused,u32 value_a,u32 value_b)
{
  DAT_003f3b40 = value_a;
  DAT_003f3b44 = value_b;
  return 1;
}
