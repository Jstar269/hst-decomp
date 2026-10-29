/* HSTMATCH module=EBOOT.BIN start=0x0029b148 end=0x0029ba08 symbol=FUN_0029b148 lang=c++ helpers=FUN_0029a584@0x0029a584-0x0029a5b0 */
/* Hand-written reconstruction from the disassembly (SetState copied from src/eboot/bundle_read_0029ade8.c, close sequence from src/eboot/net_match_teardown_0029ab94.cpp); exact match verified; names and types await human review. The empty log stub FUN_0029a584 is a same-file static placed by helpers=. Matching idioms: inlined SetState switches on the just-stored member; the "still sending" test is a const inline helper (IsSending) so x->done is reloaded later. */
#include "hst/net_xfer.h"
#include "hst/text_bank_lookup.h"

#define DRIVE_READY_BIT 0x20 /* drive-status bit polled until set */
#define POLL_USEC 1000000
#define SEEK_SET_ 0
#define SEEK_END_ 2
#define IDLE_FRAMES_TO_FINISH 120 /* idle frames after the last chunk before the send counts as done */
#define ERR_MASK_LINK_STATE 0x8000

extern "C" {
extern char DAT_002cb92c[];
extern char DAT_002cb938[];
extern char DAT_002cb8bc[];
extern char DAT_002cb8d0[];
extern char DAT_002cb8f4[];
extern char DAT_002cb68c[];
extern char DAT_002cb6a4[];
extern char DAT_002cb6dc[];
extern char DAT_002cb714[];
extern char DAT_0034179c[];
extern int DAT_00311000;
extern void *DAT_003415ac;
}

struct RefObj {
  virtual void Release(int);
  virtual void Slot0();
};

extern "C" RefObj *DAT_00338ac4;

struct MacAddr {
  char addr[6];
  MacAddr() {}
};

extern "C" {
static void FUN_0029a584(...)
{
}
int FUN_0029bd04(RefObj *);
MacAddr *FUN_0029bcfc(RefObj *);
void FUN_000bab10(RefObj *);
int FUN_000c038c(RefObj *, unsigned char, int, const MacAddr *, const MacAddr *);
void FUN_0029bb48(XferState *);
void FUN_0029ba20(XferState *);
int FUN_000c06c8(RefObj *);
unsigned int FUN_000c06b0(RefObj *);
void FUN_000c06f0(RefObj *);
void FUN_000bb190(RefObj *);
int FUN_0029ba14(void);
int FUN_0029ba08(void);
int FUN_0001efc0(void);
void FUN_0001efac(void);
void FUN_0001ebd4(void);
int FUN_0011564c(void *);
void FUN_001b1c44(void *, int);
TextBank *FUN_0018c9f4(int);
void FUN_00115088(void *, int, const char *, int, int);
void FUN_0029e108(void);
void FUN_002b7960(int, int);
int FUN_002b7dc0(void);
void FUN_000ba78c(RefObj *);
void FUN_00060224(int, int);
void FUN_0001b880(void);
void FUN_002b7958(int);
int FUN_002b7790(const char *, int, int);
long long FUN_002b77a0(int, long long, int);
int FUN_002b7720(int, void *, int);
int FUN_002b7738(int);
unsigned int FUN_002b7cf8(void);
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

/* True while the transfer is still draining (not done, and the link has been idle for at least a frame). */
static inline int IsSending(const XferState *x)
{
  int r = (x->done != 0) ^ 1;
  if (r)
    r = x->idle > 0;
  return r;
}

/* Leaves the session and releases the link and the matching object; same sequence as the match teardown. */
static inline void XferClose(XferState *x)
{
  RefObj *p;
  int r;

  FUN_002b7960(0, 0x26);
  if (x->link != 0) {
    FUN_000c06f0(x->link);
  }
  p = x->link;
  if (p != 0) {
    if (p != 0) {
      p->Release(1);
    }
    x->link = 0;
  }
  r = x->fd;
  if (r >= 0) {
    FUN_002b7738(r);
    x->fd = -1;
  }
  if (x->ready != 0) {
    x->ready = 0;
    r = FUN_002b7dc0();
    if (r < 0) {
      FUN_0029a584(DAT_002cb8f4, r);
    } else {
      FUN_0029a584(DAT_002cb8d0);
    }
    FUN_000ba78c(DAT_00338ac4);
  }
  if (DAT_00338ac4 != 0) {
    if (DAT_00338ac4 != 0) {
      DAT_00338ac4->Release(1);
    }
    DAT_00338ac4 = 0;
  }
  FUN_0029a584(DAT_002cb8bc);
}

/* Per-frame update of the file send (NET_MODE_XFER_RUN): connect, pump data, then report the outcome. */
extern "C" void FUN_0029b148(NetCtx *self)
{
  XferState *x;
  bool show;
  const char *msg;
  int locked;

  x = (XferState *)self->match;
  if (x == 0)
    return;
  switch (x->phase) {
  case XFER_WAIT_PEER:
    switch (FUN_0029bd04(DAT_00338ac4)) {
    case 0:
      FUN_000bab10(DAT_00338ac4);
      break;
    case 2: {
      x->phase = XFER_SENDING;
      MacAddr mac = *FUN_0029bcfc(DAT_00338ac4);
      FUN_000c038c(x->link, 1, 1, &mac, 0);
      break;
    }
    case 3:
      FUN_0029a584(DAT_002cb938);
      break;
    }
    break;
  case XFER_SENDING:
    FUN_0029bb48(x);
    FUN_0029ba20(x);
    if (x->sent >= x->total && FUN_000c06c8(x->link) <= 0 && ++x->idle > IDLE_FRAMES_TO_FINISH) {
      FUN_0029a584(DAT_002cb92c);
      x->phase = XFER_FINISHED;
      x->done = 1;
    }
    break;
  }
  if ((FUN_000c06b0(x->link) & ERR_MASK_LINK_STATE) == ERR_MASK_LINK_STATE) {
    x->failed = 1;
    FUN_000c06f0(x->link);
  }
  FUN_000bb190(DAT_00338ac4);
  if (FUN_0029ba14() == 0) {
    x->failed = 1;
    x->error = FUN_0029ba08();
    FUN_000c06f0(x->link);
  }
  show = false;
  msg = 0;
  locked = (unsigned char)FUN_0001efc0();
  if (locked) {
    FUN_0001efac();
  }
  x = (XferState *)self->match;
  if (!IsSending(x)) {
    if (x->failed) {
      self->unk28 = XFER_RESULT_FAILED; /* transfer result code */
      show = true;
      switch (((XferState *)self->match)->error) {
      case (int)0x80410b03:
        msg = TextGet(FUN_0018c9f4(TEXT_BANK_MESSAGES), TEXT_GROUP_ADHOC, 20);
        break;
      case (int)0x80410b0f:
        msg = TextGet(FUN_0018c9f4(TEXT_BANK_MESSAGES), TEXT_GROUP_ADHOC, 21);
        break;
      default:
        msg = TextGet(FUN_0018c9f4(TEXT_BANK_MESSAGES), TEXT_GROUP_ADHOC, 19);
        break;
      }
    } else if (x->aborted) {
      self->unk28 = XFER_RESULT_FAILED;
      show = true;
      msg = TextGet(FUN_0018c9f4(TEXT_BANK_MESSAGES), TEXT_GROUP_ADHOC, 26);
    } else if (x->done) {
      self->unk28 = XFER_RESULT_OK;
      show = true;
      msg = TextGet(FUN_0018c9f4(TEXT_BANK_MESSAGES), TEXT_GROUP_ADHOC, 3);
    } else if (FUN_0011564c(DAT_003415ac)) {
      FUN_001b1c44(DAT_0034179c, 4);
      self->unk28 = XFER_RESULT_FAILED;
      show = true;
      msg = TextGet(FUN_0018c9f4(TEXT_BANK_MESSAGES), TEXT_GROUP_ADHOC, 8);
    }
  }
  if (locked) {
    FUN_0001ebd4();
  }
  if (show) {
    SetState(self, 1); /* mode 1 has no handler in the dispatcher */
    XferClose((XferState *)self->match);
    FUN_00115088(DAT_003415ac, 2, msg, 0, 0);
    FUN_0029e108();
  }
}
