/* HSTMATCH module=hstp_trans_main.prx start=0x00241c08 end=0x00241ca0 symbol=FUN_00241c08 lang=c99 */
/* Clone of src/eboot/select_index_00231b08.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a3/v0) corrected by hand: typed the record tables as floats and used the short-circuit index guard; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_0039bf28;
extern u32 FUN_0023bc48();

struct Object_231b08 {
  char pad000[0x1e0];
  int index;
  char pad1e4[8];
  float value1;
  float value2;
  char pad1f4[0x0c];
  int valid[40];
  float values1[10];
  float values2[10];
};

void FUN_00241c08(int param_1)
{
  struct Object_231b08 *self = (struct Object_231b08 *)param_1;
  u32 uVar1;
  
  if (DAT_0039bf28 < 0) {
    uVar1 = FUN_0023bc48();
    self->index = uVar1;
  }
  else {
    self->index = DAT_0039bf28;
    DAT_0039bf28 = -1;
  }
  if (self->index < 0 || self->valid[self->index] == 0) {
    self->index = 0;
  }
  self->value1 = self->values1[self->index];
  self->value2 = self->values2[self->index];
}
