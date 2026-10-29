/* HSTMATCH module=EBOOT.BIN start=0x0022ff60 end=0x0022ffe4 symbol=FUN_0022ff60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object struct, if/else-if on the state field rewritten as a switch (cases written 3 then 4, MWCC tests them in reverse), dropped `this` argument of the case-3 callee restored; readability pass; exact match verified; names and types await human review. */
#include "hst/stateful_pane.h"

extern int FUN_001b1f84(void *, int *);
extern void FUN_0022d67c(void *);
extern void FUN_0022dd04(void *);
extern char DAT_0034179c;

/* Leave state 3 or 4: state 4 releases the handle and clears the ids first. */
void FUN_0022ff60(StatefulPane *self)
{
  switch (self->state) {
  case 3:
    FUN_0022dd04(self);
    break;
  case 4:
    if (self->handle >= 0) {
      FUN_001b1f84(&DAT_0034179c, &self->handle);
      self->handle = -1;
    }
    self->unkac = -1;
    FUN_0022d67c(self);
    break;
  }
}
