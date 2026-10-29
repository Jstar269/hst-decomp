/* HSTMATCH module=EBOOT.BIN start=0x00294840 end=0x00294f8c symbol=FUN_00294840 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idioms: the self-recursive SetState(self, 2) that MWCC inlined one level is spelled out as the static inline SetStateInner calling the out-of-line helpers; both levels switch on the just-stored member (self->state); #pragma inline_depth(8) keeps the table lookup inline under ShowMsg. */
extern char DAT_002c0e18;
extern char DAT_002c0e1c;
extern char DAT_002c0e20;
extern char DAT_002cacf0[];
extern char DAT_002cad78[];
extern char DAT_002cae44[];
extern char DAT_002cae5c[];
extern char DAT_002cacc8[];
extern char DAT_002caca4[];
extern char DAT_002cac94[];
extern char DAT_002cae34[];
extern char DAT_002cadec[];
extern char DAT_002cada4[];
extern char DAT_002cad8c[];

#include "hst/install_job.h"

/* Text bank: groups of strings, each row a list of strings. */
typedef struct Row { void **items; int count; int pad; } Row;
typedef struct Tbl { int unk0; int unk4; int count; } Tbl;
typedef struct TextBank { int unk0; int loaded; Tbl *tbl; Row *rows; } TextBank;

enum InstallState {
  INSTALL_STATE_PREPARE = 1,   /* preflight check, falls through to state 2 */
  INSTALL_STATE_THREAD_A = 4,  /* starts the first worker thread */
  INSTALL_STATE_DELAY = 5,     /* waits `timer` ticks */
  INSTALL_STATE_THREAD_B = 6,  /* shows a message, starts the second worker thread */
  INSTALL_STATE_FINISH = 8     /* closes the thread and file, shows the name */
};

enum {
  DELAY_TICKS = 60,
  WORKER_PRIORITY = 0x29,
  WORKER_STACK_SIZE = 0x4000,
  TEXT_GROUP_MESSAGES = 0x11,  /* argument of the text-bank getter */
  TEXT_GROUP_LANG = 0x13
};

typedef struct Mgr { char pad[0x58]; int **view; } Mgr;

extern Mgr *DAT_003415ac;
extern void FUN_00294684(const char *, ...);
extern int FUN_00014d64(const char *, const char *);
extern void FUN_000143b0(char *, const char *, const char *);
extern void FUN_00115088(Mgr *, int, const char *, int, int);
extern TextBank *FUN_0018c9f4(int);
extern char *FUN_0018f1ac(TextBank *, int, int);
extern int FUN_00296c50(void);
extern void FUN_0010b8cc(int *, int, int);
extern int FUN_002b79a8(int);
extern int FUN_002b7768(int, long long *);
extern int FUN_002b7738(int);
extern int FUN_002b7920(const char *, int (*)(int, void *), int, int, int, int);
extern int FUN_002b78d8(int, int, void *);
extern int FUN_00295068(int, void *);
extern int FUN_00295298(int, void *);
extern void FUN_002955c8(InstallJob *, int, const char *);
extern void FUN_002955b4(Mgr *);
extern void FUN_002951a0(InstallJob *);
extern void FUN_00295208(InstallJob *, int (*)(int, void *));
extern void FUN_00294f8c(InstallJob *);
void FUN_00294840(InstallJob *self, int state);

#pragma inline_depth(8)
static inline char *GetText(TextBank *bank, int group, int index)
{
  char *res;
  if (bank->loaded == 0) {
    res = &DAT_002c0e20;
  } else if (group < 0 || group >= bank->tbl->count) {
    res = &DAT_002c0e1c;
  } else if (index < 0 || index >= bank->rows[group].count) {
    res = &DAT_002c0e18;
  } else {
    res = bank->rows[group].items[index];
  }
  return res;
}

static inline void ShowMsg(InstallJob *self, int mode, const char *text)
{
  TextBank *bank;
  int lang;
  const char *sub;

  if (FUN_00014d64(text, DAT_002cacf0) == 0) {
    FUN_00115088(DAT_003415ac, mode, text, 0, 0);
  } else {
    bank = FUN_0018c9f4(TEXT_GROUP_LANG);
    lang = self->lang;
    if (bank->loaded == 0) {
      sub = &DAT_002c0e20;
    } else if (bank->tbl->count < 0xb) {
      sub = &DAT_002c0e1c;
    } else if (lang < 0 || !(lang < bank->rows[10].count)) {
      sub = &DAT_002c0e18;
    } else {
      sub = bank->rows[10].items[lang];
    }
    FUN_000143b0(self->msg, text, sub);
    FUN_00115088(DAT_003415ac, mode, self->msg, 0, 0);
  }
}

static inline void Refresh(Mgr *mgr)
{
  FUN_0010b8cc(*mgr->view, 0, 0);
}

static inline void DeleteThread(InstallJob *self)
{
  int r;
  if (self->thread >= 0) {
    r = FUN_002b79a8(self->thread);
    if (r != 0) {
      FUN_00294684(DAT_002cae5c, r);
    } else {
      FUN_00294684(DAT_002cae44, self->thread);
    }
    self->thread = -1;
  }
}

static inline void CreateThread(InstallJob *self, int (*entry)(int, void *))
{
  int r;
  InstallJob *arg;
  r = FUN_002b7920(DAT_002cae34, entry, WORKER_PRIORITY, WORKER_STACK_SIZE, 0, 0);
  self->thread = r;
  if (r < 0) {
    FUN_00294684(DAT_002cadec, r);
  }
  arg = self;
  if (FUN_002b78d8(self->thread, 4, &arg) < 0) {
    FUN_00294684(DAT_002cada4, self->thread);
  }
  FUN_00294684(DAT_002cad8c, self->thread);
}

static inline void Finish(InstallJob *self)
{
  int r;
  long long res;
  DeleteThread(self);
  if (self->fd >= 0) {
    if (self->async) {
      r = FUN_002b7768(self->fd, &res);
      if (r < 0) {
        FUN_00294684(DAT_002cacc8, r);
      }
      self->async = 0;
    }
    r = FUN_002b7738(self->fd);
    if (r != 0) {
      FUN_00294684(DAT_002caca4, r);
    }
    self->fd = -1;
  }
  FUN_00294684(DAT_002cac94);
}

static inline void SetStateInner(InstallJob *self, int state)
{
  self->state = state;
  switch (self->state) {
  case INSTALL_STATE_PREPARE:
    if (FUN_00296c50() == 0) {
      FUN_00294684(DAT_002cad78);
      FUN_002955c8(self, 1, FUN_0018f1ac(FUN_0018c9f4(TEXT_GROUP_MESSAGES), 15, 15));
      FUN_002955b4(DAT_003415ac);
    } else {
      FUN_00294840(self, 2);
    }
    break;
  case INSTALL_STATE_THREAD_A:
    FUN_00295208(self, FUN_00295298);
    break;
  case INSTALL_STATE_DELAY:
    self->timer = DELAY_TICKS;
    self->unk18 = self->unk10;
    break;
  case INSTALL_STATE_THREAD_B:
    FUN_002955c8(self, 0, FUN_0018f1ac(FUN_0018c9f4(TEXT_GROUP_MESSAGES), 15, 25));
    FUN_002951a0(self);
    FUN_00295208(self, FUN_00295068);
    break;
  case INSTALL_STATE_FINISH:
    FUN_00294f8c(self);
    FUN_002955c8(self, 2, self->name);
    break;
  }
}

/* Enters `state` and performs its entry action. */
void FUN_00294840(InstallJob *self, int state)
{
  self->state = state;
  switch (self->state) {
  case INSTALL_STATE_PREPARE:
    if (FUN_00296c50() == 0) {
      FUN_00294684(DAT_002cad78);
      ShowMsg(self, 1, GetText(FUN_0018c9f4(TEXT_GROUP_MESSAGES), 15, 15));
      Refresh(DAT_003415ac);
    } else {
      SetStateInner(self, 2);
    }
    break;
  case INSTALL_STATE_THREAD_A:
    CreateThread(self, FUN_00295298);
    break;
  case INSTALL_STATE_DELAY:
    self->timer = DELAY_TICKS;
    self->unk18 = self->unk10;
    break;
  case INSTALL_STATE_THREAD_B:
    ShowMsg(self, 0, GetText(FUN_0018c9f4(TEXT_GROUP_MESSAGES), 15, 25));
    DeleteThread(self);
    CreateThread(self, FUN_00295068);
    break;
  case INSTALL_STATE_FINISH:
    Finish(self);
    ShowMsg(self, 2, self->name);
    break;
  }
}
