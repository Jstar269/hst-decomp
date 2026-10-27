/* HSTMATCH module=hstp_trans_main.prx start=0x002af200 end=0x002af260 symbol=FUN_002af200 lang=c99 helpers=FUN_002ad710@0x002ad710-0x002ad73c */
/* Hand-written reconstruction from the disassembly (same-file static log stub FUN_002ad710 defined in front and placed by helpers=); exact match verified; names and types await human review. */
typedef struct Install {
    char pad[0x28];
    int thread;
} Install;

extern int FUN_002c7748(int thid);
extern char DAT_002dbbc4[]; /* "ERROR: sceKernelDeleteThread(): return 0x%08x\n" */
extern char DAT_002dbac4[]; /* "Install End.\n" */

static void FUN_002ad710(...)
{
}

void FUN_002af200(Install *self)
{
    if (self->thread >= 0) {
        int ret = FUN_002c7748(self->thread);
        if (ret != 0) {
            FUN_002ad710(DAT_002dbbc4, ret);
        }
        self->thread = -1;
    }
    FUN_002ad710(DAT_002dbac4);
}
