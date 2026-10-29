/* HSTMATCH module=EBOOT.BIN start=0x0029febc end=0x0029ff1c symbol=FUN_0029febc lang=c99 helpers=FUN_0029e3cc@0x0029e3cc-0x0029e3f8 */
/* Hand-written reconstruction from the disassembly (same source as the Sharing twin src/sharing_main/install_end_002af200.c, addresses substituted; same-file static log stub FUN_0029e3cc defined in front and placed by helpers=); exact match verified; names and types await human review. */
#include "hst/install_thread.h"

extern int FUN_002b79a8(int thid);
extern char DAT_002cbb24[]; /* "ERROR: sceKernelDeleteThread(): return 0x%08x\n" */
extern char DAT_002cba24[]; /* "Install End.\n" */

static void FUN_0029e3cc(...)
{
}

void FUN_0029febc(InstallThread *self)
{
    if (self->thread >= 0) {
        int ret = FUN_002b79a8(self->thread);
        if (ret != 0) {
            FUN_0029e3cc(DAT_002cbb24, ret);
        }
        self->thread = -1;
    }
    FUN_0029e3cc(DAT_002cba24);
}
