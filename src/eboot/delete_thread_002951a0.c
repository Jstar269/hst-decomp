/* HSTMATCH module=EBOOT.BIN start=0x002951a0 end=0x00295208 symbol=FUN_002951a0 lang=c99 helpers=FUN_00294684@0x00294684-0x002946b0 */
/* Hand-written reconstruction from the disassembly (same-file static log stub FUN_00294684 defined in front and placed by helpers=); exact match verified; names and types await human review. */
typedef struct Obj {
    char pad[0x24];
    int thread;
} Obj;

extern char DAT_002cae44[]; /* "Delete Thread [0x%08x]\n" */
extern char DAT_002cae5c[]; /* "ERROR: sceKernelDeleteThread(): return 0x%08x\n" */
extern int FUN_002b79a8(int thid);

static void FUN_00294684(...)
{
}

void FUN_002951a0(Obj *self)
{
    int r;

    if (self->thread >= 0) {
        r = FUN_002b79a8(self->thread);
        if (r)
            FUN_00294684(DAT_002cae5c, r);
        else
            FUN_00294684(DAT_002cae44, self->thread);
        self->thread = -1;
    }
}
