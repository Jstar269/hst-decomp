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

typedef struct Row { void **items; int count; int pad; } Row;
typedef struct Tbl { int a; int b; int count; } Tbl;
typedef struct Obj { int x; int ok; Tbl *tbl; Row *rows; } Obj;

typedef struct Mgr { char pad[0x58]; int **view; } Mgr;

typedef struct Inst {
  int state;            /* 0x00 */
  int f04, f08, f0c;
  int f10;              /* 0x10 */
  int f14;
  int f18;              /* 0x18 */
  int f1c, f20;
  int thread;           /* 0x24 */
  char name[0x180];     /* 0x28 */
  char msg[0x180];      /* 0x1a8 */
  int timer;            /* 0x328 */
  int fd;               /* 0x32c */
  unsigned char async;  /* 0x330 */
  char pad331[0xeb44 - 0x331];
  int lang;             /* 0xeb44 */
} Inst;

extern Mgr *DAT_003415ac;
extern void FUN_00294684(const char *, ...);
extern int FUN_00014d64(const char *, const char *);
extern void FUN_000143b0(char *, const char *, const char *);
extern void FUN_00115088(Mgr *, int, const char *, int, int);
extern Obj *FUN_0018c9f4(int);
extern char *FUN_0018f1ac(Obj *, int, int);
extern int FUN_00296c50(void);
extern void FUN_0010b8cc(int *, int, int);
extern int FUN_002b79a8(int);
extern int FUN_002b7768(int, long long *);
extern int FUN_002b7738(int);
extern int FUN_002b7920(const char *, int (*)(int, void *), int, int, int, int);
extern int FUN_002b78d8(int, int, void *);
extern int FUN_00295068(int, void *);
extern int FUN_00295298(int, void *);
extern void FUN_002955c8(Inst *, int, const char *);
extern void FUN_002955b4(Mgr *);
extern void FUN_002951a0(Inst *);
extern void FUN_00295208(Inst *, int (*)(int, void *));
extern void FUN_00294f8c(Inst *);
void FUN_00294840(Inst *self, int state);

#pragma inline_depth(8)
static inline char *GetStr(Obj *o, int i, int j)
{
  char *res;
  if (o->ok == 0) {
    res = &DAT_002c0e20;
  } else if (i < 0 || i >= o->tbl->count) {
    res = &DAT_002c0e1c;
  } else if (j < 0 || j >= o->rows[i].count) {
    res = &DAT_002c0e18;
  } else {
    res = o->rows[i].items[j];
  }
  return res;
}

static inline void ShowMsg(Inst *self, int mode, const char *text)
{
  Obj *o;
  int lang;
  const char *sub;

  if (FUN_00014d64(text, DAT_002cacf0) == 0) {
    FUN_00115088(DAT_003415ac, mode, text, 0, 0);
  } else {
    o = FUN_0018c9f4(0x13);
    lang = self->lang;
    if (o->ok == 0) {
      sub = &DAT_002c0e20;
    } else if (o->tbl->count < 0xb) {
      sub = &DAT_002c0e1c;
    } else if (lang < 0 || !(lang < o->rows[10].count)) {
      sub = &DAT_002c0e18;
    } else {
      sub = o->rows[10].items[lang];
    }
    FUN_000143b0(self->msg, text, sub);
    FUN_00115088(DAT_003415ac, mode, self->msg, 0, 0);
  }
}

static inline void Refresh(Mgr *m)
{
  FUN_0010b8cc(*m->view, 0, 0);
}

static inline void DeleteThread(Inst *self)
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

static inline void CreateThread(Inst *self, int (*entry)(int, void *))
{
  int r;
  Inst *arg;
  r = FUN_002b7920(DAT_002cae34, entry, 0x29, 0x4000, 0, 0);
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

static inline void Finish(Inst *self)
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

static inline void SetStateInner(Inst *self, int state)
{
  self->state = state;
  switch (self->state) {
  case 1:
    if (FUN_00296c50() == 0) {
      FUN_00294684(DAT_002cad78);
      FUN_002955c8(self, 1, FUN_0018f1ac(FUN_0018c9f4(0x11), 15, 15));
      FUN_002955b4(DAT_003415ac);
    } else {
      FUN_00294840(self, 2);
    }
    break;
  case 4:
    FUN_00295208(self, FUN_00295298);
    break;
  case 5:
    self->timer = 60;
    self->f18 = self->f10;
    break;
  case 6:
    FUN_002955c8(self, 0, FUN_0018f1ac(FUN_0018c9f4(0x11), 15, 25));
    FUN_002951a0(self);
    FUN_00295208(self, FUN_00295068);
    break;
  case 8:
    FUN_00294f8c(self);
    FUN_002955c8(self, 2, self->name);
    break;
  }
}

void FUN_00294840(Inst *self, int state)
{
  self->state = state;
  switch (self->state) {
  case 1:
    if (FUN_00296c50() == 0) {
      FUN_00294684(DAT_002cad78);
      ShowMsg(self, 1, GetStr(FUN_0018c9f4(0x11), 15, 15));
      Refresh(DAT_003415ac);
    } else {
      SetStateInner(self, 2);
    }
    break;
  case 4:
    CreateThread(self, FUN_00295298);
    break;
  case 5:
    self->timer = 60;
    self->f18 = self->f10;
    break;
  case 6:
    ShowMsg(self, 0, GetStr(FUN_0018c9f4(0x11), 15, 25));
    DeleteThread(self);
    CreateThread(self, FUN_00295068);
    break;
  case 8:
    Finish(self);
    ShowMsg(self, 2, self->name);
    break;
  }
}
