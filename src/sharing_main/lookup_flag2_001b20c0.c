/* HSTMATCH module=hstp_trans_main.prx start=0x001b20c0 end=0x001b2140 symbol=FUN_001b20c0 lang=c99 */
/* Clone of src/eboot/lookup_flag2_001a4af4.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sibling of lookup_flag_001a4b74.c: when the object's own byte flag at +0x2a4 is set and the global
   manager DAT_003e1e04 has its flag byte (+0x178) clear the function answers 1 right away, otherwise it
   looks for the value 2 in the int table at +0x360 (length +0x364) and returns whether the parallel table
   at +0x36c holds a non-zero entry for the same index.
   Matching idioms: same as lookup_flag_001a4b74.c (strength reduction off, the length read in two
   different forms); the value 2 is compared with the loaded entry first ("arr[i] == 2" gives retail's
   "bnel v0,v1"). */
#pragma opt_strength_reduction off

#include "hst/types.h"

typedef struct {
  char pad178[0x178];
  u8 flag;
} G2;

typedef struct {
  char pad2a4[0x2a4];
  u8 flag;
  char pad360[0x360 - 0x2a5];
  int *arr;
  unsigned count;
  char pad36c[0x36c - 0x368];
  int *other;
} Self;

extern G2 *DAT_003e1e04;

int FUN_001b20c0(Self *self)
{
  if (self->flag != 0) {
    if (DAT_003e1e04->flag == 0) {
      return 1;
    }
  }
  unsigned i = 0;
  if (self->count != 0) {
    do {
      if (self->arr[i] == 2) {
        return self->other[i] != 0;
      }
      i++;
    } while (i < *(unsigned *)((char *)self + 0x364));
  }
  return 0;
}
