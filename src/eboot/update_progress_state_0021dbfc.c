/* HSTMATCH module=EBOOT.BIN start=0x0021dbfc end=0x0021dc84 symbol=FUN_0021dbfc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: store the source field before calculating the percentage from that stored value. */
#include "hst/lobby_gauge.h"

#define PERCENT_FULL 100.0f

extern void FUN_0021df6c(LobbyGauge *self,int page);
extern void FUN_0021e090(LobbyGauge *self,float percent);
extern int FUN_002af920(int handle);

/* Refreshes the gauge: reads the progress value, converts it to a percentage of rangeMin..rangeMax, then updates
   the page and the bar. */
void FUN_0021dbfc(LobbyGauge *self)
{
  float percent;
  self->unk1fc = FUN_002af920(self->unk170);
  self->value = self->source;
  percent = (float)(self->value - self->rangeMin) * PERCENT_FULL /
             (float)(self->rangeMax - self->rangeMin);
  FUN_0021df6c(self,self->unk1cc - 1);
  FUN_0021e090(self,percent);
}
