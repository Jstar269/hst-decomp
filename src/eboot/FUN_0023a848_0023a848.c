/* HSTMATCH module=EBOOT.BIN start=0x0023a848 end=0x0023a900 symbol=FUN_0023a848 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: wrote the threshold as count >= 2 to match the retail comparison result register; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/hist_obj.h"

/* Config byte holding two signed 2-bit fields in its low nibble. */
typedef struct ConfigByte {
  char pad00[0x89];
  signed char bits;  /* 0x89 */
} ConfigByte;

extern ConfigByte * DAT_002cfc8c;
extern void FUN_002395f8();
extern void FUN_00239a7c();
extern void FUN_0023c2ac();

/* Runs the helpers, then shifts both histories one entry older and records the two 2-bit fields of the config byte as the newest entries. */
void FUN_0023a848(HistObj *self)
{
  FUN_002395f8();
  if (self->unk3c >= 2) {
    FUN_00239a7c(self);
  }
  FUN_0023c2ac(self->unk50);
  self->histA[4] = self->histA[3];
  self->histB[4] = self->histB[3];
  self->histA[3] = self->histA[2];
  self->histB[3] = self->histB[2];
  self->histA[2] = self->histA[1];
  self->histB[2] = self->histB[1];
  self->histA[1] = self->histA[0];
  self->histB[1] = self->histB[0];
  self->histA[0] = ((int)DAT_002cfc8c->bits << 0x1e) >> 0x1e;
  self->histB[0] = ((int)DAT_002cfc8c->bits << 0x1a) >> 0x1e;
}
