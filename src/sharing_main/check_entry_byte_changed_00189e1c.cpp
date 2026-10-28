/* HSTMATCH module=hstp_trans_main.prx start=0x00189e1c end=0x00189ea0 symbol=FUN_00189e1c lang=c++ */
/* Clone of src/eboot/check_entry_byte_changed_0017d728.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the two nested conditions are one && chain (the pre-call test and a comma expression with the call and byte compare) feeding if r=1 else r=0, which gives retail's unthreaded beq/b/li/move tail; exact match verified; names and types await human review. */
#include "hst/types.h"
struct Obj { char pad[8]; int *tab; };
extern "C" void FUN_000942c8(void *, unsigned);
extern "C" int FUN_0020d154(void *, int, int);

extern "C" int FUN_00189e1c(Obj *self, int idx, unsigned v)
{
  char *o;
  int r;
  if (FUN_0020d154((char *)self + 0x2e4, idx, 0) == 0 && (o = (char *)self->tab[idx], FUN_000942c8(o + 0x10, v), (u8)v != *(u8 *)(o + 0x85))) r = 1; else r = 0;
  return r;
}
