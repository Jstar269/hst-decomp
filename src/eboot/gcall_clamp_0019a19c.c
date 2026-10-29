/* HSTMATCH module=EBOOT.BIN start=0x0019a19c end=0x0019a210 symbol=FUN_0019a19c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0) corrected by hand: byte field at +0xea read as unsigned char (lbu) instead of char; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern float FUN_000ede98(float value,float limit,float rate,float step);
extern void FUN_00103128();
extern void FUN_00199f78();
extern int FUN_001b1c44();

typedef struct Source {
  char pad00[0xea];
  u8 flag;  /* 0xea */
} Source;

typedef struct Ramp {
  char pad00[0x54];
  Source *source;  /* 0x54 */
  char pad58[4];
  float value;     /* 0x5c */
} Ramp;

/* Call the shared helper when the source flag is set, then ease value toward its limit and refresh. */
void FUN_0019a19c(Ramp *self)
{
  float next;
  
  if (self->source->flag != 0) {
    FUN_001b1c44((int *)&DAT_0034179c,1);
  }
  next = FUN_000ede98(self->value,1.0f,0.5f,0.005f);
  self->value = next;
  FUN_00199f78(self);
  FUN_00103128(self);
}
