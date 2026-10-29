/* HSTMATCH module=EBOOT.BIN start=0x0029ba20 end=0x0029bb48 symbol=FUN_0029ba20 lang=c99 helpers=FUN_0029a584@0x0029a584-0x0029a5b0 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/send_progress_0029ba20.c, completed with its same-file static helper FUN_0029a584 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
#include "hst/net_xfer.h"

/* Progress bar widget: value range at 0x1c/0x20. */
typedef struct Bar {
    char pad[0x1c];
    float min_val;
    float max_val;
} Bar;

/* Progress screen (DAT_003415ac); the bar is at 0x64. */
typedef struct Screen {
    char pad[0x64];
    Bar *bar;
} Screen;

extern Screen *DAT_003415ac;
extern char DAT_002cb9b0[];
extern unsigned char FUN_000c0634(RefObj *, char *, int);
extern int FUN_000ff3cc(char *, int);
extern int FUN_000ff678(RefObj *, char *, int, int);
extern void FUN_00113580(float, Bar *);
static void FUN_0029a584(...)
{
}

static inline void SetBarRange(float min_val, float max_val, Screen *scr)
{
    Bar *bar = scr->bar;
    bar->min_val = min_val;
    bar->max_val = max_val;
}

static inline void SetBarValue(float val, Screen *scr)
{
    FUN_00113580(val, scr->bar);
}

/* Takes a chunk from the ring buffer, sends it over the link and updates the progress bar. */
void FUN_0029ba20(XferState *x)
{
    int r;

    if (x->canSend != 0) {
        x->chunk = FUN_000ff678(x->ring, x->sendBuf, XFER_SEND_SIZE, 0);
    }
    if (x->chunk > 0) {
        x->canSend = FUN_000c0634(x->link, x->sendBuf, x->chunk);
        if (x->firstSend != 0) {
            x->firstSend = 0;
        }
    }
    if (x->canSend != 0) {
        x->sent = x->sent + x->chunk;
        if (x->total == XFER_TOTAL_UNKNOWN) {
            r = FUN_000ff3cc(x->sendBuf, x->sent);
            if (r >= 0) {
                x->total = r;
                FUN_0029a584(DAT_002cb9b0, r);
            }
        }
        SetBarRange(0.0f, (float)x->total, DAT_003415ac);
        SetBarValue((float)x->sent, DAT_003415ac);
    }
}
