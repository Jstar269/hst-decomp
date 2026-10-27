/* HSTMATCH module=EBOOT.BIN start=0x0029a830 end=0x0029a8bc symbol=FUN_0029a830 lang=c99 helpers=FUN_0029a584@0x0029a584-0x0029a5b0 */
/* Hand-written reconstruction from the disassembly (same-file static log stub FUN_0029a584 defined in front and placed by helpers=); exact match verified; names and types await human review. */
extern unsigned int DAT_0034b320; /* flag word; the wait loop polls bit 2 after the disconnect request */
extern unsigned int DAT_0034b324;
extern char DAT_002ffef4[]; /* "NetStopDisconnect() called.\n" */
extern char DAT_002fff14[]; /* "ERROR: sceNetAdhocctlDisconnect() failed. ret = 0x%x\n" */
extern int FUN_002b7d68(void);   /* the sceNetAdhocctlDisconnect import (per the error string) */
extern int FUN_002b7888(int usec); /* called with 1000000 between polls (a delay) */

static void FUN_0029a584(...)
{
}

int FUN_0029a830(void)
{
    int r;

    FUN_0029a584(DAT_002ffef4);
    DAT_0034b320 = 0;
    DAT_0034b324 = 0;
    r = FUN_002b7d68();
    if (r < 0) {
        FUN_0029a584(DAT_002fff14, r);
        return r;
    }
    for (;;) {
        if (DAT_0034b320 & 4)
            break;
        FUN_002b7888(1000000);
    }
    DAT_0034b320 &= ~4;
    return 0;
}
