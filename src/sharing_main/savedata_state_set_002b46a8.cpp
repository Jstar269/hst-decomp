/* HSTMATCH module=hstp_trans_main.prx start=0x002b46a8 end=0x002b497c symbol=FUN_002b46a8 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/savedata_state_set_002a4f18.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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

extern const char *DAT_003a98a8;
extern const char *DAT_003a98ac;
extern int DAT_003a98b0;
extern int DAT_003a98b4;
extern int DAT_003a98b8;
extern unsigned char DAT_003a98bc;
extern char DAT_002d10d4[];
extern char DAT_002d10d0[];
extern char DAT_002d10cc[];
extern void *DAT_003eaaac;
extern void *DAT_003ea8ec;

struct Dev {
  virtual void v0();
  virtual void m1(int);
};
extern Dev *DAT_003e1a00;

enum {
  INFO_SET_ID = 17,       /* argument that selects the info object */
  TEXTS_A_MIN_LEVEL = 0x15,
  TEXTS_B_MIN_LEVEL = 13
};

extern "C" {
void FUN_0001b584(void);
Info *FUN_001991d4(int);
int FUN_001a4bcc(void *, const char *, int, void *);
void FUN_0011fe78(void *, int, int, int, int);
int FUN_001108a4(void *, RunParams *);
void FUN_002b46a8(SaveScreen *, int);
}

/* String idx of list A, or a placeholder when the lists are unavailable or too short. */
static inline const char *PickA(Info *o, int idx)
{
  if (o->enabled == 0) return DAT_002d10d4;
  if (o->limits->level < TEXTS_A_MIN_LEVEL) return DAT_002d10d0;
  if (o->lists->countA <= idx) return DAT_002d10cc;
  return o->lists->textsA[idx];
}

/* String idx of list B, with the same fallbacks. */
static inline const char *PickB(Info *o, int idx)
{
  if (o->enabled == 0) return DAT_002d10d4;
  if (o->limits->level < TEXTS_B_MIN_LEVEL) return DAT_002d10d0;
  if (o->lists->countB <= idx) return DAT_002d10cc;
  return o->lists->textsB[idx];
}

/* Enter a state: 1 queues one message, 2 starts the operation (falling through to DONE on success). */
extern "C" void FUN_002b46a8(SaveScreen *self, int state)
{
  self->state = state;
  switch (state) {
  case SAVE_STATE_IDLE:
    break;
  case SAVE_STATE_MESSAGE: {
    const char *p = PickA(FUN_001991d4(INFO_SET_ID), 6);
    int h = FUN_001a4bcc(DAT_003eaaac, p, SAVE_TEXT_SIZE, self->text[4]);
    FUN_0011fe78(DAT_003ea8ec, 1, h, 0, 0);
    break;
  }
  case SAVE_STATE_RUN: {
    FUN_0001b584();
    if (DAT_003e1a00 != 0) DAT_003e1a00->m1(0);
    RunParams loc;
    loc.gameId = DAT_003a98a8;
    loc.dirName = DAT_003a98ac;
    loc.msgA = DAT_003a98b0;
    loc.msgB = DAT_003a98b4;
    loc.msgC = DAT_003a98b8;
    loc.flag = DAT_003a98bc;
    loc.msgA = FUN_001a4bcc(DAT_003eaaac, PickB(FUN_001991d4(INFO_SET_ID), 32), SAVE_TEXT_SIZE, self->text[0]);
    loc.msgB = FUN_001a4bcc(DAT_003eaaac, PickA(FUN_001991d4(INFO_SET_ID), 1), SAVE_TEXT_SIZE, self->text[1]);
    loc.msgC = FUN_001a4bcc(DAT_003eaaac, PickA(FUN_001991d4(INFO_SET_ID), 0), SAVE_TEXT_SIZE, self->text[2]);
    if (FUN_001108a4(self->worker, &loc) == 0) {
      self->unk5d4 = 0;
    } else {
      FUN_002b46a8(self, SAVE_STATE_DONE);
    }
    break;
  }
  case SAVE_STATE_DONE:
    break;
  }
}
