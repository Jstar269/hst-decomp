/* HSTMATCH module=EBOOT.BIN start=0x0029e550 end=0x0029ef50 symbol=FUN_0029e550 lang=c++ helpers=FUN_0029e3cc@0x0029e3cc-0x0029e3f8 rodata=0x002cb9c8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The empty log stub FUN_0029e3cc is a same-file static placed by helpers= (its preserved v0 carries the FUN_002990e0 result past the two log calls). Matching idioms: one-case switch with default for the state==0 test; the save-size compare written need-first (NeedKB(recv) <= remain). */
enum RecvState {
  RECV_STATE_CONNECT,      /* waiting for the peer handshake */
  RECV_STATE_AWAIT_ACK,
  RECV_STATE_CHECK_SPACE,  /* compares the needed size with the free space */
  RECV_STATE_AWAIT_START,
  RECV_STATE_TRANSFER,     /* worker thread running */
  RECV_STATE_SETTLE,       /* counts down `wait` */
  RECV_STATE_FINALIZE,
  RECV_STATE_ABORTING,
  RECV_STATE_END           /* terminal: waits for the dialog to close */
};

enum {
  BLOCK_SIZE = 0x8000,            /* save data is counted in whole blocks */
  RESERVE_KB = 0x60,              /* extra space needed on top of the blocks */
  RECV_SIZE_UNKNOWN = 0x7fffffff, /* total size not announced yet */
  RECV_ERR_NO_SPACE = (int)0x8001001c
};

struct RefObj {
  virtual void Release(int);
  virtual void Slot0();
};

struct Listener {
  virtual void V0();
  virtual void V1();
  virtual void V2();
  virtual void V3();
  virtual void V4();
  virtual void V5();
  virtual void V6();
  virtual void V7();
  virtual void V8();
  virtual void V9();
  virtual void V10();
  virtual void Notify();
};

struct MacAddr {
  char addr[6];
  MacAddr() {}
};

struct Recv {
  int state;               /* 0x00 */
  RefObj *obj;             /* 0x04 */
  int unk08, unk0c;
  int got;                 /* 0x10 */
  int total;               /* 0x14 */
  int extra;               /* 0x18 */
  int progress;            /* 0x1c */
  int error;               /* 0x20 */
  unsigned char failed;    /* 0x24 */
  unsigned char finished;  /* 0x25 */
  int thread;              /* 0x28 */
  char message[0x180];     /* 0x2c */
  int wait;                /* 0x1ac */
  Listener *listener;      /* 0x1b0 */
  char pad1b4[0x201c4 - 0x1b4];
  char text[0x400];        /* 0x201c4 */
};

struct ReceiveScreen {
  char pad[0x3c];
  Recv *recv;
};

extern "C" {
extern char DAT_0034179c[];
extern char DAT_0034b32c[];
extern char DAT_002cbfbc[];
extern char DAT_002cbfa4[];
extern char DAT_002cbf90[];
extern void *DAT_003415ac;
extern void *DAT_0034176c;
extern RefObj *DAT_00338ac4;

static void FUN_0029e3cc(...)
{
}
int FUN_002a0370(void *);
int FUN_001156fc(void *);
int FUN_0011574c(void *);
int FUN_001156ac(void *);
int FUN_0011564c(void *);
int FUN_001155c0(void *);
int FUN_001156d4(void *);
void FUN_001b1c44(void *, int);
int FUN_0029bd04(RefObj *);
MacAddr *FUN_0029bcfc(RefObj *);
void FUN_000bab10(RefObj *);
void FUN_002b7da0(void *, MacAddr *);
int FUN_000c038c(RefObj *, unsigned char, int, const MacAddr *, const MacAddr *);
void FUN_0029f92c(Recv *, int);
void FUN_0029ef70(Recv *, int);
unsigned int FUN_000c06b0(RefObj *);
int FUN_000c06dc(RefObj *);
void FUN_000c06f0(RefObj *);
void FUN_0029f818(Recv *);
void FUN_0029f70c(Recv *, int);
void *FUN_0018c9f4(int);
char *FUN_0018f1ac(void *, int, int);
char *FUN_00198278(void *, const char *, int, char *);
void FUN_00115088(void *, int, const char *, int, int);
int FUN_00296cac(void);
int FUN_002990e0(int, long long *);
void FUN_002955b4(void *);
int FUN_0029ef50(void);
int FUN_002b7908(int);
void FUN_00295cdc(void *);
void FUN_0004784c(void);
void FUN_00295ccc(void *, float, float);
void FUN_00295cc4(void *, float);
void FUN_000bb190(RefObj *);
int FUN_0029ba14(void);
int FUN_0029ba08(void);
void FUN_000149a8(char *, const char *);
}

static inline char *Text(Recv *recv, int string_id)
{
  return FUN_00198278(DAT_0034176c, FUN_0018f1ac(FUN_0018c9f4(0x11), 14, string_id), 0x400, recv->text);
}

static inline void Fail(Recv *recv, int code)
{
  recv->failed = 1;
  FUN_0029ef70(recv, code);
  FUN_0029f92c(recv, RECV_STATE_END);
}

static inline int NeedKB(Recv *recv)
{
  return ((recv->total + (BLOCK_SIZE - 1)) / BLOCK_SIZE + (recv->extra + (BLOCK_SIZE - 1)) / BLOCK_SIZE) * BLOCK_SIZE / 1024 + RESERVE_KB;
}

extern "C" void FUN_0029e550(ReceiveScreen *self)
{
  Recv *recv;
  RefObj *obj;
  int result;
  int error_code;
  MacAddr mine;
  long long remain;  /* free space in KB */

  recv = self->recv;
  if (FUN_002a0370(DAT_003415ac) == 0) {
    if (FUN_001156fc(DAT_003415ac)) {
      FUN_001b1c44(DAT_0034179c, 3);
    } else if (FUN_0011574c(DAT_003415ac)) {
      FUN_001b1c44(DAT_0034179c, 4);
    } else if (FUN_001156ac(DAT_003415ac)) {
      FUN_001b1c44(DAT_0034179c, 1);
    }
  }
  switch (recv->state) {
  case RECV_STATE_CONNECT:
    switch (FUN_0029bd04(DAT_00338ac4)) {
    case 0:
      FUN_000bab10(DAT_00338ac4);
      break;
    case 2: {
      FUN_002b7da0(DAT_0034b32c, &mine);
      MacAddr peer = *FUN_0029bcfc(DAT_00338ac4);
      FUN_000c038c(recv->obj, 0, 1, &mine, &peer);
      FUN_0029f92c(recv, RECV_STATE_AWAIT_ACK);
      break;
    }
    case 3:
      FUN_0029e3cc(DAT_002cbfbc);
      break;
    }
    break;
  default:
    obj = recv->obj;
    if (obj != 0) {
      if (recv->failed != 0) {
        if (obj != 0) {
          if (obj != 0) {
            obj->Release(1);
          }
          recv->obj = 0;
        }
      } else {
        if (recv->finished == 0 && FUN_000c06b0(obj) != 0 && FUN_000c06b0(recv->obj) != 0x4000) {
          recv->failed = 1;
          FUN_001b1c44(DAT_0034179c, 5);
          FUN_00115088(DAT_003415ac, 0, Text(recv, 22), 0, 0);
          obj = recv->obj;
          if (obj != 0) {
            if (obj != 0) {
              obj->Release(1);
            }
            recv->obj = 0;
          }
        } else if (recv->got >= recv->total && FUN_000c06dc(recv->obj) <= 0) {
          recv->finished = 1;
        } else {
          FUN_0029f818(recv);
        }
      }
    }
    break;
  }
  switch (recv->state) {
  case RECV_STATE_CONNECT:
  case RECV_STATE_AWAIT_ACK:
  case RECV_STATE_CHECK_SPACE:
    FUN_0029f70c(recv, 0x20000);
    break;
  }
  switch (recv->state) {
  case RECV_STATE_CONNECT:
    if (FUN_0011564c(DAT_003415ac)) {
      Fail(recv, 0x80000006);
    }
    break;
  case RECV_STATE_AWAIT_ACK:
    if (FUN_001155c0(DAT_003415ac)) {
      if (FUN_001156d4(DAT_003415ac) == 0) {
        result = FUN_00296cac();
        if (result < 0) {
          Fail(recv, result);
        } else {
          FUN_00115088(DAT_003415ac, 0, Text(recv, 18), 0, 0);
          FUN_0029f92c(recv, RECV_STATE_CHECK_SPACE);
        }
      } else {
        Fail(recv, 0x80000006);
      }
    }
    break;
  case RECV_STATE_CHECK_SPACE:
    if (recv->total == RECV_SIZE_UNKNOWN) {
      if (FUN_0011564c(DAT_003415ac)) {
        Fail(recv, 0x80000006);
      }
    } else {
      result = FUN_002990e0(0, &remain);
      FUN_0029e3cc(DAT_002cbfa4, remain);
      FUN_0029e3cc(DAT_002cbf90, NeedKB(recv));
      if (result == 0) {
        if (NeedKB(recv) <= remain) {
          FUN_00115088(DAT_003415ac, 1, Text(recv, 17), 0, 0);
          FUN_002955b4(DAT_003415ac);
          FUN_0029f92c(recv, RECV_STATE_AWAIT_START);
        } else {
          Fail(recv, RECV_ERR_NO_SPACE);
        }
      } else if (result == (int)0x80020321 || result == (int)0x80010013) {
        Fail(recv, 0x80010013);
      } else {
        Fail(recv, result);
      }
    }
    break;
  case RECV_STATE_AWAIT_START:
    if (FUN_001155c0(DAT_003415ac)) {
      if (FUN_001156d4(DAT_003415ac) == 0) {
        FUN_00115088(DAT_003415ac, 4, Text(recv, 6), 0, 0);
        FUN_0029f92c(recv, RECV_STATE_TRANSFER);
      } else {
        Fail(recv, 0x80000006);
      }
    }
    break;
  case RECV_STATE_TRANSFER:
    if (FUN_0029ef50() != 0 || FUN_0011564c(DAT_003415ac) != 0) {
      if (FUN_0029ef50() != 0) {
        FUN_001b1c44(DAT_0034179c, 4);
      }
      recv->failed = 1;
      FUN_0029f92c(recv, RECV_STATE_ABORTING);
    } else if (FUN_002b7908(recv->thread) == 0) {
      if (recv->error == 0) {
        FUN_0029f92c(recv, RECV_STATE_SETTLE);
      } else {
        recv->failed = 1;
        FUN_0029ef70(recv, recv->error);
        FUN_0029f92c(recv, RECV_STATE_END);
      }
    }
    break;
  case RECV_STATE_SETTLE:
    if (recv->wait-- <= 0) {
      FUN_0029f92c(recv, RECV_STATE_FINALIZE);
    }
    break;
  case RECV_STATE_FINALIZE:
    if (FUN_002b7908(recv->thread) == 0) {
      FUN_0029ef70(recv, recv->error);
      FUN_0029f92c(recv, RECV_STATE_END);
    }
    break;
  case RECV_STATE_ABORTING:
    if (FUN_002b7908(recv->thread) == 0) {
      recv->failed = 1;
      FUN_0029ef70(recv, recv->error);
      FUN_0029f92c(recv, RECV_STATE_END);
    }
    break;
  case RECV_STATE_END:
    if (FUN_001155c0(DAT_003415ac)) {
      FUN_00295cdc(DAT_003415ac);
      FUN_0004784c();
    }
    break;
  }
  FUN_00295ccc(DAT_003415ac, 0.0f, (float)recv->total);
  FUN_00295cc4(DAT_003415ac, (float)recv->progress);
  FUN_000bb190(DAT_00338ac4);
  switch (recv->state) {
  case RECV_STATE_SETTLE:
  case RECV_STATE_FINALIZE:
  case RECV_STATE_ABORTING:
  case RECV_STATE_END:
    break;
  default:
    if (FUN_0029ba14() == 0) {
      recv->failed = 1;
      error_code = FUN_0029ba08();
      switch (error_code) {
      case (int)0x80410b03:
      case (int)0x80410b0f:
        FUN_0029ef70(recv, error_code);
        break;
      default:
        FUN_000149a8(recv->message, Text(recv, 22));
        break;
      }
      FUN_000c06f0(recv->obj);
      FUN_0029f92c(recv, RECV_STATE_END);
    }
    break;
  }
  if (recv->listener != 0) {
    recv->listener->Notify();
  }
}
