/* HSTMATCH module=EBOOT.BIN start=0x000e3944 end=0x000e3a10 symbol=FUN_000e3944 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: pointer local declared and initialised before the counter (swaps the v1/a0 registers of the unrolled clear loop), typed arguments; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rec_array_obj.h"

extern char DAT_002c070c[];
extern char DAT_00307690[];
extern void *FUN_0001f06c(void *);
extern void FUN_000e3a74(void *);
extern void FUN_000e3ba4(void *);

/* Constructor: run the base constructor, clear the state words from the info pointer on, store the arguments and build the arrays. */
RecArrayObj *FUN_000e3944(RecArrayObj *self, unsigned unk4c, unsigned handle, unsigned info)
{
  unsigned *clear;
  int done;
  FUN_0001f06c(self);
  self->vtable = DAT_00307690;
  clear = (unsigned *)&self->info;
  done = 0;
  do {
    clear[0] = 0;
    clear[1] = 0;
    clear[2] = 0;
    clear[3] = 0;
    clear[4] = 0;
    clear[5] = 0;
    clear[6] = 0;
    done = done + 8;
    clear[7] = 0;
    clear = clear + 8;
  } while (done < 0x19);
  *clear = 0;
  self->unk4c = unk4c;
  self->handle = handle;
  self->info = (RecCountInfo *)DAT_002c070c;
  if (info != 0) {
    self->info = (RecCountInfo *)info;
  }
  FUN_000e3a74(self);
  FUN_000e3ba4(self);
  self->unka8 = 0x43000000;
  self->unkac = 0;
  return self;
}
