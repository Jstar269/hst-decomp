/* HSTMATCH module=EBOOT.BIN start=0x0021db30 end=0x0021dbbc symbol=FUN_0021db30 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the float zero argument and placed the receiver first in the helper prototype; readability pass; exact match verified; names and types await human review. */
#include "hst/lobby_gauge.h"

extern void FUN_0021dbbc(LobbyGauge *);
extern void FUN_0021dd14(LobbyGauge *);
extern void FUN_0021df6c(LobbyGauge *, int);
extern void FUN_0021e090(LobbyGauge *, float);
extern void FUN_0021e14c(LobbyGauge *, int);
extern void FUN_0021e20c(LobbyGauge *, float);
extern void FUN_0021e25c(LobbyGauge *, float, float);
extern void FUN_0021e4cc(LobbyGauge *, int, int);

/* Resets the gauge: clears the stored state and runs the helper reset calls in order. */
void FUN_0021db30(LobbyGauge *self)
{
  self->unk1e8 = -1;
  self->unk1ec = 0;
  FUN_0021df6c(self,0);
  FUN_0021e090(self,0.0f);
  FUN_0021e20c(self,1.0f);
  FUN_0021e4cc(self,0,0);
  FUN_0021e25c(self,0.0f,0.0f);
  FUN_0021e14c(self,0);
  FUN_0021dbbc(self);
  FUN_0021dd14(self);
}
