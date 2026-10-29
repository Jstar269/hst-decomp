/* HSTMATCH module=EBOOT.BIN start=0x001991f8 end=0x00199244 symbol=FUN_001991f8 lang=c99 */
/* Hand-written reconstruction (external matching lane): the flag global is written with a literal 1/0
   in each arm of an inverted if (mode != 1), which is what puts the zero-store on the fallthrough
   and the body out of line; writing `DAT = mode == 1` after the if instead re-derives the
   comparison (xori/sltiu) and keeps mode alive in s0 across the call. Exact match verified; names
   and types await human review. */
#include "hst/install_flow.h"

extern unsigned char DAT_00341771;
extern void FUN_002b7cd8(InstallPart **);

/* Switch the flow to `mode`; entering run mode also sets the pane word, starts the part and raises the global flag. */
void FUN_001991f8(InstallFlow *self, int mode)
{
    self->mode = mode;
    if (mode != INSTALL_MODE_RUN) {
        DAT_00341771 = 0;
    } else {
        self->pane->unk30 = 8;
        FUN_002b7cd8(&self->part);
        DAT_00341771 = 1;
    }
}
