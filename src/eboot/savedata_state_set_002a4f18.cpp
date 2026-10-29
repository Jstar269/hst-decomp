/* HSTMATCH module=EBOOT.BIN start=0x002a4f18 end=0x002a51ec symbol=FUN_002a4f18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified. State setter of a save/load style screen: state 1 resolves one message string and queues it, state 2 builds a 6-field parameter block (game id and directory name strings from the .data globals, three message handles) and passes it to FUN_0010aae4, falling through to state 3 on success. Matching idioms: switch with empty case 0/3 (tests emitted in reverse source order), two inline string pickers (PickA/PickB) whose limit compares and list bounds follow the retail slti/bgtz forms. Names and types await human review. */
#include "hst/savedata_screen.h"

/* Limits record that the info object points at. */
struct InfoLimits {
  int pad0[2];
  int level;              /* 0x08 selects whether the text lists are available */
};

/* Two string lists: the second (A) at +0xf0 and the first (B) at +0x90, each with its length. */
struct TextLists {
  char pad0[0x90];
  const char **textsB;    /* 0x90 */
  int countB;             /* 0x94 */
  char pad1[0xf0 - 0x98];
  const char **textsA;    /* 0xf0 */
  int countA;             /* 0xf4 */
};

struct Info {
  int pad0;
  int enabled;            /* 0x04 zero selects the placeholder string */
  InfoLimits *limits;     /* 0x08 */
  TextLists *lists;       /* 0x0c */
};

/* Parameter block handed to the worker: defaults copied from .data, then the message handles filled in. */
struct RunParams {
  const char *gameId;
  const char *dirName;
  int msgA;
  int msgB;
  int msgC;
  unsigned char flag;
};

extern const char *DAT_0030080c;
extern const char *DAT_00300810;
extern int DAT_00300814;
extern int DAT_00300818;
extern int DAT_0030081c;
extern unsigned char DAT_00300820;
extern char DAT_002c0e20[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e18[];
extern void *DAT_0034176c;
extern void *DAT_003415ac;

struct Dev {
  virtual void v0();
  virtual void m1(int);
};
extern Dev *DAT_003386c0;

enum {
  INFO_SET_ID = 17,       /* argument that selects the info object */
  TEXTS_A_MIN_LEVEL = 0x15,
  TEXTS_B_MIN_LEVEL = 13
};

extern "C" {
void FUN_0001b880(void);
Info *FUN_0018c9f4(int);
int FUN_00198278(void *, const char *, int, void *);
void FUN_00115088(void *, int, int, int, int);
int FUN_0010aae4(void *, RunParams *);
void FUN_002a4f18(SaveScreen *, int);
}

/* String idx of list A, or a placeholder when the lists are unavailable or too short. */
static inline const char *PickA(Info *o, int idx)
{
  if (o->enabled == 0) return DAT_002c0e20;
  if (o->limits->level < TEXTS_A_MIN_LEVEL) return DAT_002c0e1c;
  if (o->lists->countA <= idx) return DAT_002c0e18;
  return o->lists->textsA[idx];
}

/* String idx of list B, with the same fallbacks. */
static inline const char *PickB(Info *o, int idx)
{
  if (o->enabled == 0) return DAT_002c0e20;
  if (o->limits->level < TEXTS_B_MIN_LEVEL) return DAT_002c0e1c;
  if (o->lists->countB <= idx) return DAT_002c0e18;
  return o->lists->textsB[idx];
}

/* Enter a state: 1 queues one message, 2 starts the operation (falling through to DONE on success). */
extern "C" void FUN_002a4f18(SaveScreen *self, int state)
{
  self->state = state;
  switch (state) {
  case SAVE_STATE_IDLE:
    break;
  case SAVE_STATE_MESSAGE: {
    const char *p = PickA(FUN_0018c9f4(INFO_SET_ID), 6);
    int h = FUN_00198278(DAT_0034176c, p, SAVE_TEXT_SIZE, self->text[4]);
    FUN_00115088(DAT_003415ac, 1, h, 0, 0);
    break;
  }
  case SAVE_STATE_RUN: {
    FUN_0001b880();
    if (DAT_003386c0 != 0) DAT_003386c0->m1(0);
    RunParams loc;
    loc.gameId = DAT_0030080c;
    loc.dirName = DAT_00300810;
    loc.msgA = DAT_00300814;
    loc.msgB = DAT_00300818;
    loc.msgC = DAT_0030081c;
    loc.flag = DAT_00300820;
    loc.msgA = FUN_00198278(DAT_0034176c, PickB(FUN_0018c9f4(INFO_SET_ID), 32), SAVE_TEXT_SIZE, self->text[0]);
    loc.msgB = FUN_00198278(DAT_0034176c, PickA(FUN_0018c9f4(INFO_SET_ID), 1), SAVE_TEXT_SIZE, self->text[1]);
    loc.msgC = FUN_00198278(DAT_0034176c, PickA(FUN_0018c9f4(INFO_SET_ID), 0), SAVE_TEXT_SIZE, self->text[2]);
    if (FUN_0010aae4(self->worker, &loc) == 0) {
      self->unk5d4 = 0;
    } else {
      FUN_002a4f18(self, SAVE_STATE_DONE);
    }
    break;
  }
  case SAVE_STATE_DONE:
    break;
  }
}
