/* HSTMATCH module=EBOOT.BIN start=0x0029bb48 end=0x0029bcfc symbol=FUN_0029bb48 lang=c99 */
/* Hand-written reconstruction from the disassembly (started from wip/stream_read_tick_0029bb48.c, Ghidra pseudocode); exact match verified; names and types await human review. Matching idiom: `return;` at the end of the first arm (puts MWCC's branch cleanup in the mode that keeps the dead originals of delay-slot copies); FUN_000ff5b0 takes the byte count as 3rd arg and FUN_0029a584 the error code as 2nd arg, both dropped by Ghidra. */
#include "hst/net_xfer.h"

extern char DAT_002cb984[];
extern char DAT_002cb95c[];
extern int FUN_002b77a8(int, int *);
extern int FUN_002b7748(int, char *, int);
extern int FUN_000ff5b0(RefObj *, char *, int);
extern void FUN_00011090(char *, char *, int);
extern void FUN_002b7958(int);
extern void FUN_0029a584(char *, ...);

#define RETRY_DELAY_USEC 100

/* One tick of the file reader: first push pending bytes into the ring buffer, otherwise poll the
   asynchronous read and move the finished block into the ring (keeping what does not fit). */
void FUN_0029bb48(XferState *x)
{
    int res[2]; /* 64-bit async result; the low word is the byte count */
    int r;
    int e;
    int n;

    if (x->spillLeft > 0) {
        r = FUN_000ff5b0(x->ring, x->spillPtr, x->spillLeft);
        x->spillLeft = x->spillLeft - r;
        x->spillPtr = x->spillPtr + r;
        if (x->spillLeft == 0) {
            e = FUN_002b7748(x->fd, x->recvBuf, XFER_RECV_SIZE);
            if (e != 0)
                FUN_0029a584(DAT_002cb95c, e);
        }
        return;
    }
    {
        r = FUN_002b77a8(x->fd, res);
        if (r == 0) {
            n = res[0];
            if (n < 0) {
                FUN_0029a584(DAT_002cb984, n);
                FUN_002b7958(RETRY_DELAY_USEC);
                e = FUN_002b7748(x->fd, x->recvBuf, XFER_RECV_SIZE);
                if (e != 0)
                    FUN_0029a584(DAT_002cb95c, e);
            } else {
                x->recvLen = n;
                r = FUN_000ff5b0(x->ring, x->recvBuf, n);
                if (r < x->recvLen) {
                    x->spillLeft = x->recvLen - r;
                    x->spillPtr = x->spillBuf;
                    FUN_00011090(x->spillBuf, x->recvBuf + r,
                                 x->spillLeft);
                } else {
                    e = FUN_002b7748(x->fd, x->recvBuf, XFER_RECV_SIZE);
                    if (e != 0)
                        FUN_0029a584(DAT_002cb95c, e);
                }
            }
        }
    }
}
