/* HSTMATCH module=hstp_trans_main.prx start=0x002a9ab4 end=0x002a9b40 symbol=FUN_002a9ab4 lang=c99 helpers=FUN_002a9808@0x002a9808-0x002a9834 */
/* Hand-written reconstruction from the disassembly (same-file static log stub FUN_002a9808 defined in front and placed by helpers=); exact match verified; names and types await human review. */
extern unsigned int DAT_003f4660; /* flag word; the wait loop polls bit 2 after the disconnect request */
extern unsigned int DAT_003f4664;
extern char DAT_003a8dc8[]; /* "NetStopDisconnect() called.\n" */
extern char DAT_003a8de8[]; /* "ERROR: sceNetAdhocctlDisconnect() failed. ret = 0x%x\n" */
extern int FUN_002c7af0(void);   /* the sceNetAdhocctlDisconnect import (per the error string) */
extern int FUN_002c7628(int usec); /* called with 1000000 between polls (a delay) */

static void FUN_002a9808(...)
{
}

#define FLAG_DISCONNECTED 4 /* set in the flag word once the disconnect finished */
#define POLL_USEC 1000000

/* Requests an ad-hoc disconnect and waits until the handler reports it; returns 0 or the error. */
int FUN_002a9ab4(void)
{
    int r;

    FUN_002a9808(DAT_003a8dc8);
    DAT_003f4660 = 0;
    DAT_003f4664 = 0;
    r = FUN_002c7af0();
    if (r < 0) {
        FUN_002a9808(DAT_003a8de8, r);
        return r;
    }
    for (;;) {
        if (DAT_003f4660 & FLAG_DISCONNECTED)
            break;
        FUN_002c7628(POLL_USEC);
    }
    DAT_003f4660 &= ~FLAG_DISCONNECTED;
    return 0;
}
