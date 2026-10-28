/* HSTMATCH module=EBOOT.BIN start=0x0029ade8 end=0x0029b014 symbol=FUN_0029ade8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/net_adhoc.h"

extern void FUN_00060224(int, int);
extern void FUN_0001b880(void);
extern void FUN_0029a584(char *, ...);
extern void FUN_002b7958(int);
extern int FUN_002b7790(char *, int, int);
extern long long FUN_002b77a0(int, long long, int);
extern int FUN_002b7720(int, int, int);
extern int FUN_002b7738(int);
extern unsigned int FUN_002b7cf8(void);
extern int DAT_00311000;
extern char DAT_002cb68c[];
extern char DAT_002cb6a4[];
extern char DAT_002cb6dc[];
extern char DAT_002cb714[];

#define DRIVE_READY_BIT 0x20 /* drive-status bit polled until set */
#define POLL_USEC 1000000

/* Bundle-read modes (NetCtx.mode) */
enum { BUNDLE_IDLE = 0, BUNDLE_RESET = 3, BUNDLE_READ = 4 };

/* Sets the bundle-read mode; in BUNDLE_READ it opens the bundle file, sizes it and reads it into ctx->bundle. */
void FUN_0029ade8(NetCtx *ctx, int mode)
{
    int fd;
    int n;

    ctx->mode = mode;
    switch (mode) {
    case BUNDLE_IDLE:
        return;
    case BUNDLE_RESET:
        ctx->count = 0;
        return;
    case BUNDLE_READ:
        FUN_00060224(DAT_00311000, 1);
        FUN_0001b880();
        FUN_0029a584(DAT_002cb714, DAT_002cb6dc);
        while ((fd = FUN_002b7790(DAT_002cb6a4, 1, 0)) < 0) {
            FUN_0001b880();
        }
        ctx->bundleSize = (int)FUN_002b77a0(fd, 0LL, 2);
        while (ctx->bundleSize < 0) {
            FUN_0001b880();
            ctx->bundleSize = (int)FUN_002b77a0(fd, 0LL, 2);
        }
        while (FUN_002b77a0(fd, 0LL, 0) < 0) {
            FUN_0001b880();
        }
        for (;;) {
            while ((FUN_002b7cf8() & DRIVE_READY_BIT) == 0) {
                FUN_0029a584(DAT_002cb68c);
                FUN_002b7958(POLL_USEC);
            }
            n = ctx->bundleSize;
            if (FUN_002b7720(fd, (int)ctx->bundle, n) == n)
                break;
            FUN_002b7958(POLL_USEC);
        }
        n = FUN_002b7738(fd);
        while (n < 0) {
            FUN_002b7958(POLL_USEC);
            n = FUN_002b7738(fd);
        }
        FUN_00060224(DAT_00311000, 0);
        return;
    }
}
