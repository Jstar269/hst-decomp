/* HSTMATCH module=EBOOT.BIN start=0x0008ac88 end=0x0008ad40 symbol=FUN_0008ac88 lang=c99 data=0x002d241c */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: fixed inverted condition to logical OR; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d241c-0x002d2428) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/play_flow.h"

extern char *DAT_00338b44;
extern void FUN_0001f558(void *, int, int, int);
extern void FUN_0008822c(const void *, ...);
extern void FUN_0008ad40(void *);
extern int FUN_0008add8(void *);
extern int FUN_000df000(void *);

enum { STATE_RUN = 7 }; /* state in which the slots are serviced */

void FUN_0008ac88(PlayFlowObj *self)
{
    if (self->state == STATE_RUN) {
        if (FUN_000df000(DAT_00338b44) != 0 || *(unsigned char *)(DAT_00338b44 + 0x5d) != 0) {
            FUN_0008ad40(self);
            if (FUN_0008add8(self) != 0) {
                self->nextState = 4;
            }
        } else {
            self->nextState = 6;
        }
    } else {
        FUN_0008822c("PlayEnd %d\n", *(int *)(DAT_00338b44 + 0x9c));
        FUN_0001f558(self, 20, 0, 0);
        self->nextState = 5;
    }
}
