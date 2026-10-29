/* HSTMATCH module=EBOOT.BIN start=0x0021dbbc end=0x0021dbfc symbol=FUN_0021dbbc lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_0021dbbc.c (tag: a1) */
#include "hst/lobby_gauge.h"

extern unsigned int DAT_0034179c;
extern int FUN_001b1f84(void *, int *);

/* Releases the gauge's sound handle (if any) and marks it empty. */
void FUN_0021dbbc(LobbyGauge *self)
{
    if (self->handle >= 0) {
        FUN_001b1f84(&DAT_0034179c, &self->handle);
        self->handle = -1;
    }
}
