/* HSTMATCH module=EBOOT.BIN start=0x00128138 end=0x001281e8 symbol=FUN_00128138 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/avatar_obj.h"

/* Constants of the linear congruential step applied to the random seed. */
#define LCG_MULTIPLIER 0x343fdU
#define LCG_INCREMENT 0x269ec3U
#define LCG_SAMPLE_MASK 0x7fffU /* 15-bit sample, scaled to [0, 1) by 1/32768 */

extern int DAT_002da8f8; /* lower limit */
extern int DAT_002da8fc; /* upper limit */
extern int FUN_0001342c(void); /* random seed */

/* Stores a random integer between the two limits (lower + sample * (upper - lower)) in the avatar. */
void FUN_00128138(Avatar *self)
{
  unsigned int seed = (unsigned int)FUN_0001342c();
  unsigned int bits = seed * LCG_MULTIPLIER + LCG_INCREMENT;
  unsigned int sample = (bits >> 16) & LCG_SAMPLE_MASK;
  float value = (float)DAT_002da8f8 + (float)sample * (1.0f / 32768.0f) * (float)(DAT_002da8fc - DAT_002da8f8);
  self->unk340 = (int)value;
}
