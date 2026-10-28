/* HSTMATCH module=hstp_trans_main.prx start=0x00264d0c end=0x00264d50 symbol=FUN_00264d0c lang=c99 */
/* Clone of src/eboot/idx_flags_slot_null_00254894.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Obj_00264d0c {
  int f0;
  u8 a4[236];
  u8 af0[236];
  int slot[1];
} Obj_00264d0c;

int FUN_00264d0c(Obj_00264d0c *o, int idx)
{
  int ok = (o->af0[idx] != 0) ^ 1;
  if (ok) ok = o->a4[idx] != 0;
  if (ok) ok = o->slot[idx] == 0;
  return ok;
}
