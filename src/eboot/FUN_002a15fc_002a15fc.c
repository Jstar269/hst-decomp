/* HSTMATCH module=EBOOT.BIN start=0x002a15fc end=0x002a165c symbol=FUN_002a15fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed the mixed integer and float helper parameters in EABI order; readability pass; exact match verified; names and types await human review. */
#include "hst/anim_host.h"

extern void FUN_00057bc0(AnimHost *, int, int, float, float, float);
extern unsigned int FUN_00057b58(AnimHost *, int, unsigned int, float);

/* Starts the given animation on a channel after clearing it. */
void FUN_002a15fc(AnimHost *host,int channel,unsigned int anim)
{
  FUN_00057bc0(host,channel,-1,0.0f,0.0f,0.0f);
  FUN_00057b58(host,channel,anim,0.0f);
  return;
}
