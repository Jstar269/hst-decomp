/* HSTMATCH module=EBOOT.BIN start=0x001e51a4 end=0x001e521c symbol=FUN_001e51a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: typed float query results and the mixed int/float updater arguments; readability pass; exact match verified; names and types await human review. */
#include "hst/result_scene.h"

extern char DAT_002ec168[];
extern char DAT_002ec174[];
extern float FUN_000657e4(int, char *, int);
extern int FUN_001ee224();
extern void FUN_0021780c(void *, int, float, float);

/* Read two float config values and use them to set up the animator at 0x43c. */
void FUN_001e51a4(ResultScene *self)
{
  float first;
  float second;
  
  first = FUN_000657e4(FUN_001ee224(),DAT_002ec168,1);
  second = FUN_000657e4(FUN_001ee224(),DAT_002ec174,1);
  FUN_0021780c(&self->anim43c,(int)second,first,1.0f);
  return;
}
