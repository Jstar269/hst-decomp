/* HSTMATCH module=EBOOT.BIN start=0x00254894 end=0x002548d8 symbol=FUN_00254894 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Obj_00254894 {
  int f0;
  u8 a4[236];
  u8 af0[236];
  int slot[1];
} Obj_00254894;

int FUN_00254894(Obj_00254894 *o, int idx)
{
  int ok = (o->af0[idx] != 0) ^ 1;
  if (ok) ok = o->a4[idx] != 0;
  if (ok) ok = o->slot[idx] == 0;
  return ok;
}
