/* HSTMATCH module=EBOOT.BIN start=0x0029bf68 end=0x0029c794 symbol=FUN_0029bf68 lang=c99 helpers=FUN_0029a584@0x0029a584-0x0029a5b0 */
/* Hand-written reconstruction from the disassembly (SetState copied from src/eboot/bundle_read_0029ade8.c); exact match verified; names and types await human review. The empty log stub FUN_0029a584 is a same-file static placed by helpers=. Matching idiom: the inlined SetState switches on the just-stored member (self->state). */
#include "hst/net_xfer.h"
#include "hst/text_bank_lookup.h"

#define DRIVE_READY_BIT 0x20 /* drive-status bit polled until set */
#define POLL_USEC 1000000
#define SEEK_SET_ 0
#define SEEK_END_ 2

extern char DAT_002cb848[];
extern char DAT_002cb824[];
extern char DAT_002ffef4[];
extern char DAT_002fff14[];
extern char DAT_002ffd3c[];
extern char DAT_002ffd74[];
extern char DAT_002ffda4[];
extern char DAT_002ffdd4[];
extern char DAT_002cb63c[];
extern char DAT_002cb5e8[];
extern char DAT_002cb8a4[];
extern char DAT_002cb880[];
extern char DAT_002cb7ec[];
extern char DAT_002fe878[];
extern char DAT_002fe888[];
extern char DAT_002cb68c[];
extern char DAT_002cb6a4[];
extern char DAT_002cb6dc[];
extern char DAT_002cb714[];
extern unsigned int DAT_0034b320;
extern unsigned int DAT_0034b324;
extern int DAT_002ffcc8;
extern int DAT_00311000;
extern void *DAT_003415ac;
extern void *DAT_00338ac4;

/* Parameter block for the matching-session setup call (FUN_000ba9e0 fills the first part). */
typedef struct SessionDesc {
  int head[4];
  int size;                /* memory pool size */
  int align;
  const char *name;
  const char *files;
} SessionDesc;

extern int FUN_002b7dc0(void);
extern int FUN_002b7d68(void);
extern void FUN_002b7888(int);
extern int FUN_002b7d70(int);
extern int FUN_002b7d78(void);
extern int FUN_002b7e40(void);
extern int FUN_002b7d90(void);
extern int FUN_002b7cc0(int);
extern TextBank *FUN_0018c9f4(int);
extern char *FUN_0018f1ac(TextBank *, int, int);
extern void FUN_00115088(void *, int, const char *, int, int);
extern void FUN_00103628(void *, int);
extern void FUN_002956e0(RefObj *);
extern void *FUN_00000bcc(int);
extern void *FUN_000ba2a8(void *);
extern void *FUN_000c02d8(void *);
extern void FUN_000ba9e0(void *, SessionDesc *);
extern unsigned char FUN_000ba57c(void *, SessionDesc *);
extern int FUN_002b7790(const char *, int, int);
extern void FUN_0001b880(void);
extern void FUN_0029c794(XferState *);
extern void FUN_00060224(int, int);
extern void FUN_002b7958(int);
extern long long FUN_002b77a0(int, long long, int);
extern int FUN_002b7720(int, void *, int);
extern int FUN_002b7738(int);
extern unsigned int FUN_002b7cf8(void);

static void FUN_0029a584(...)
{
}

/* Sets the net mode; in NET_MODE_BUNDLE_READ it reads the bundle file into ctx->bundle. */
static inline void SetState(NetCtx *self, int mode)
{
  int fd;
  int n;

  self->mode = mode;
  switch (self->mode) {
  case NET_MODE_IDLE:
    return;
  case NET_MODE_BUNDLE_RESET:
    self->count = 0;
    return;
  case NET_MODE_BUNDLE_READ:
    FUN_00060224(DAT_00311000, 1);
    FUN_0001b880();
    FUN_0029a584(DAT_002cb714, DAT_002cb6dc);
    while ((fd = FUN_002b7790(DAT_002cb6a4, 1, 0)) < 0) {
      FUN_0001b880();
    }
    self->bundleSize = (int)FUN_002b77a0(fd, 0LL, SEEK_END_);
    while (self->bundleSize < 0) {
      FUN_0001b880();
      self->bundleSize = (int)FUN_002b77a0(fd, 0LL, SEEK_END_);
    }
    while (FUN_002b77a0(fd, 0LL, SEEK_SET_) < 0) {
      FUN_0001b880();
    }
    for (;;) {
      while ((FUN_002b7cf8() & DRIVE_READY_BIT) == 0) {
        FUN_0029a584(DAT_002cb68c);
        FUN_002b7958(POLL_USEC);
      }
      n = self->bundleSize;
      if (FUN_002b7720(fd, self->bundle, n) == n)
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

#define NET_EVENT_DISCONNECTED 4 /* bit set in DAT_0034b320 once the disconnect finished */

/* Net-mode handler for XFER_START (leave the ad-hoc session, then open the bundle file and set up the transfer)
   and XFER_STOP (leave the session, return to idle). */
int FUN_0029bf68(NetCtx *self)
{
  int r;
  XferState *x;
  void *p;
  SessionDesc desc;

  r = FUN_002b7dc0();
  if (r < 0) {
    FUN_0029a584(DAT_002cb848, r);
  } else {
    FUN_0029a584(DAT_002cb824);
  }
  self->active = 0;
  FUN_0029a584(DAT_002ffef4);
  DAT_0034b320 = 0;
  DAT_0034b324 = 0;
  r = FUN_002b7d68();
  if (r < 0) {
    FUN_0029a584(DAT_002fff14, r);
  } else {
    for (;;) {
      if (DAT_0034b320 & NET_EVENT_DISCONNECTED)
        break;
      FUN_002b7888(POLL_USEC);
    }
    DAT_0034b320 &= ~NET_EVENT_DISCONNECTED;
  }
  if (DAT_002ffcc8 > 0) {
    r = FUN_002b7d70(DAT_002ffcc8);
    if (r < 0) {
      FUN_0029a584(DAT_002ffd3c, r);
    }
    DAT_002ffcc8 = -1;
  }
  r = FUN_002b7d78();
  if (r < 0) {
    FUN_0029a584(DAT_002ffd74, r);
  }
  r = FUN_002b7e40();
  if (r < 0) {
    FUN_0029a584(DAT_002ffda4, r);
  }
  r = FUN_002b7d90();
  if (r < 0) {
    FUN_0029a584(DAT_002ffdd4, r);
  }
  switch (self->mode) {
  case NET_MODE_XFER_START:
    x = (XferState *)self->match;
    FUN_0029a584(DAT_002cb8a4);
    FUN_002956e0(x->ring);
    p = FUN_00000bcc(0x288);
    if (p != 0)
      p = FUN_000ba2a8(p);
    DAT_00338ac4 = p;
    p = FUN_00000bcc(0x1c);
    if (p != 0)
      p = FUN_000c02d8(p);
    x->link = p;
    x->phase = XFER_WAIT_PEER;
    x->sent = 0;
    x->canSend = 1;
    x->firstSend = 1;
    x->done = 0;
    x->failed = 0;
    x->aborted = 0;
    x->recvLen = 0;
    x->chunk = 0;
    x->spillPtr = 0;
    x->spillLeft = 0;
    x->total = XFER_TOTAL_UNKNOWN;
    x->idle = 0;
    x->error = 0;
    FUN_000ba9e0(DAT_00338ac4, &desc);
    desc.size = 0xb800;
    desc.align = 0x1000;
    desc.name = DAT_002fe878;
    desc.files = DAT_002fe888;
    x->ready = FUN_000ba57c(DAT_00338ac4, &desc);
    FUN_0029a584(DAT_002cb880, DAT_002cb7ec);
    while ((x->fd = FUN_002b7790(DAT_002cb7ec, 1, 0)) < 0) {
      FUN_0001b880();
    }
    FUN_0029c794(x);
    FUN_00115088(DAT_003415ac, 4, FUN_0018f1ac(FUN_0018c9f4(TEXT_BANK_MESSAGES), TEXT_GROUP_ADHOC, 2), 0, 0);
    SetState(self, NET_MODE_XFER_RUN);
    break;
  case NET_MODE_XFER_STOP:
    r = FUN_002b7cc0(0x101);
    if (r < 0) {
      FUN_0029a584(DAT_002cb63c, r);
    }
    r = FUN_002b7cc0(0x100);
    if (r < 0) {
      FUN_0029a584(DAT_002cb5e8, r);
    }
    FUN_00115088(DAT_003415ac, 2, TextGet(FUN_0018c9f4(TEXT_BANK_MESSAGES), TEXT_GROUP_ADHOC, 8), 0, 0);
    SetState(self, NET_MODE_IDLE);
    break;
  default:
    FUN_00103628(DAT_003415ac, 1);
    break;
  }
  return 0;
}
