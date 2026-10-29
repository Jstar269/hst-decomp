/* HSTMATCH module=EBOOT.BIN start=0x0024d908 end=0x0024da48 symbol=FUN_0024d908 lang=c99 data=0x002fbdf8 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002fbdf8-0x002fbe06) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: calls are `pow(double,double)` (0xc07c is newlib pow), the float sum `(i+1)+NeedX` is computed in single precision before the double conversion, and the destination walker is the same base pointer in the i==0 branch via `threshold[i]` (base + i*4 + 0x30); exact match verified; names and types await human review. */
#include "hst/aityaku_table.h"

extern float FUN_000657e4(AityakuTable *table, const char *column, int row);
extern double pow(double,double);

/* Fill the level thresholds: level i needs pow(i + 1 + NeedX, 2) + NeedY more than the previous one. */
void FUN_0024d908(AityakuTable *self)
{
  float need[AITYAKU_LEVELS] = {0};
  float needX;
  float needY;
  int i;

  for (i = 0; i < AITYAKU_LEVELS; i++) {
    needX = FUN_000657e4(self,"NeedX",1);
    needY = FUN_000657e4(self,"NeedY",1);
    need[i] = needY + pow((i + 1) + needX,2.0);
    if (i == 0) {
      self->threshold[i] = need[i];
    }
    else {
      self->threshold[i] = self->threshold[i - 1] + need[i];
    }
  }
}
