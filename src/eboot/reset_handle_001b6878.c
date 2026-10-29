/* HSTMATCH module=EBOOT.BIN start=0x001b6878 end=0x001b68c4 symbol=FUN_001b6878 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: changed -1<handle to handle>=0 and used &DAT_0034179c; readability pass; exact match verified; names and types await human review. */
#include "hst/state_obj.h"

extern char DAT_0034179c;
extern void FUN_001b1f84(void *, int *);
extern int FUN_001b2af0(void *, int);

/* Release the held handle (when there is one) and acquire a fresh one in the next field. */
void FUN_001b6878(StateObj *self)
{
    if (self->handle4c >= 0) {
        FUN_001b1f84(&DAT_0034179c, &self->handle4c);
    }
    self->handle50 = FUN_001b2af0(&DAT_0034179c, 0);
}
