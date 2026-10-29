/* HSTMATCH module=EBOOT.BIN start=0x00225b00 end=0x00225b6c symbol=FUN_00225b00 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_00225b00.c (tag: a1) */
#include "hst/mode_parts.h"

extern int DAT_002f1210[];
extern void FUN_000f68b4(void *, int);
extern void FUN_00225b78(ModeObj *, int);

/* Apply table entry `index` to the +0x30 part and, when `notify` is set, show its text. */
void FUN_00225b00(ModeObj *self, int index, int unused2, int unused3, int notify)
{
    FUN_000f68b4(self->parts->part30, DAT_002f1210[index]);
    if (notify != 0) {
        FUN_00225b78(self, index);
    }
}
