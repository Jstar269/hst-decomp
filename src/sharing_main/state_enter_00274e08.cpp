/* HSTMATCH module=hstp_trans_main.prx start=0x00274e08 end=0x002752ec symbol=FUN_00274e08 lang=c++ rodata=0x002dae2c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* State-change handler (Ghidra pseudocode ram-0x00274e08.c and the EXACT EBOOT sibling src/eboot/status_update_00263d20.cpp
   as guides): the state switch is a 10-entry jump table, the previous-state switch lists its labels 4, 5, 3/default so
   MWCC tests 3, 5, 4; the list member is re-read through the typed Self in each arm (an int-based
   `*(void **)(p + 0x58)` makes MWCC CSE the member address); both flag words are read into locals before the ||
   test, as retail loads them; the vector clear passes the allocator Tag() by value. Same code as EBOOT 0x00263f8c. */
struct Obj {
  virtual void v0();
  virtual void v1(int);
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
};

struct Obj0 {
  virtual void v0();
  virtual void v1(int);
};

struct List : Obj {
  char pad4[0xd8 - 4];
  int fd8;
  char padDC[0x114 - 0xdc];
  unsigned char f114;
};

struct Flags {
  char pad[0x74];
  int f74;
  int f78;
};

struct Rect {
  short pad0[2];
  short x0;
  short pad6;
  short x1;
};

struct Bar {
  char pad0[0x10];
  Rect **rect;
  char pad14[0x60 - 0x14];
  float f60;
};

struct Vec {
  int data;
  int size;
};

struct Game {
  char pad0[0x8c];
  Vec vec;
};

struct Self {
  char pad0[0x58];
  List *list;
  char pad5c[0x51c - 0x5c];
  unsigned char f51c;
  char pad51d[0x640 - 0x51d];
  Flags *flags;
  char pad644[0x658 - 0x644];
  Obj0 *f658;
  char pad65c[0x680 - 0x65c];
  Obj *f680;
  Bar *bar;
  char pad688[0x6a0 - 0x688];
  Obj *f6a0;
  void *f6a4;
  char pad6a8[0x6d8 - 0x6a8];
  void *f6d8;
  void *f6dc;
  void *f6e0;
  char pad6e4[0x1850 - 0x6e4];
  int state;
  int prev;
  int timer;
};

struct Tag {};

struct Adhoc {
  char pad0[0x178];
  unsigned char f178;
};

struct Text {
  char pad0[8];
  int count;
};

struct Strs {
  char pad0[0xc0];
  char **strs;
  int count;
};

struct Bank {
  int pad0;
  int loaded;
  Text *text;
  Strs *strs;
};

extern "C" {
extern Obj *DAT_003f3af4;
extern Adhoc *DAT_003e1e04;
extern Game *DAT_003ea8ec;
extern void *DAT_003daec4;
extern char DAT_003eaad8[];
extern char DAT_002d10d4[];
extern char DAT_002d10d0[];
extern char DAT_002d10cc[];

void FUN_00105470(void *, int);
void FUN_001118ac(List *, int, int);
void FUN_00111aa4(List *, int, int);
Bank *FUN_001991d4(int);
void FUN_0011e940(Game *, int, char *, int, int);
void FUN_000be4b4(Adhoc *);
void FUN_00274b9c(Self *);
void FUN_002752ec(Self *);
void FUN_001c2280(float, float, void *);
void FUN_00108f54(Game *, int);
void FUN_00121330(Vec *, int, Tag);
void FUN_0026a46c(Self *);
void FUN_000647e0(float, void *, int);
void FUN_002701c8(Obj *, int);

void FUN_00274e08(Self *self, int state)
{
  self->prev = self->state;
  self->state = state;
  self->timer = 0;
  self->f6a0->v1(1);
  FUN_00105470(self->f6a4, 1);
  switch (self->state) {
  case 0:
  case 1:
    FUN_00274b9c(self);
    break;
  case 2: {
    self->list->v1(0);
    FUN_001118ac(self->list, 2, 5);
    List *l = self->list;
    l->fd8 = 2;
    l->f114 = 0;
    switch (self->prev) {
    case 4:
      FUN_00111aa4(self->list, 1, 0);
      break;
    case 5:
      FUN_00111aa4(self->list, 3, 0);
      break;
    case 3:
    default:
      FUN_00111aa4(self->list, 0, 0);
      break;
    }
    self->f658->v1(0);
    self->f680->v1(1);
    int f74 = self->flags->f74;
    int f78 = self->flags->f78;
    if (f74 != 0 || f78 != 0) {
      FUN_00105470(self->f6e0, 0);
      FUN_00105470(self->f6d8, 0);
      FUN_00105470(self->f6dc, 0);
    }
    DAT_003f3af4->v7();
    break;
  }
  case 3: {
    self->f658->v1(1);
    self->f680->v1(1);
    int f74 = self->flags->f74;
    int f78 = self->flags->f78;
    if (f74 != 0 || f78 != 0) {
      FUN_00105470(self->f6e0, 0);
      FUN_00105470(self->f6d8, 0);
      FUN_00105470(self->f6dc, 0);
    }
    int flag = 0;
    if (DAT_003e1e04 != 0 && DAT_003e1e04->f178 != 0) {
      flag = 1;
    }
    FUN_002701c8(DAT_003f3af4, flag);
    self->list->v1(1);
    break;
  }
  case 4: {
    self->list->v1(0);
    FUN_001118ac(self->list, 6, 0xb);
    List *l = self->list;
    l->fd8 = 1;
    l->f114 = 0;
    self->f658->v1(1);
    self->f680->v1(0);
    FUN_002752ec(self);
    break;
  }
  case 5: {
    self->list->v1(1);
    char *msg;
    Bank *b = FUN_001991d4(0x11);
    if (b->loaded == 0) {
      msg = DAT_002d10d4;
    } else if (b->text->count < 0x11) {
      msg = DAT_002d10d0;
    } else if (b->strs->count < 3) {
      msg = DAT_002d10cc;
    } else {
      msg = b->strs->strs[2];
    }
    FUN_0011e940(DAT_003ea8ec, 1, msg, 0, 0);
    break;
  }
  case 6: {
    self->list->v1(1);
    char *msg;
    Bank *b = FUN_001991d4(0x11);
    if (b->loaded == 0) {
      msg = DAT_002d10d4;
    } else if (b->text->count < 0x11) {
      msg = DAT_002d10d0;
    } else if (b->strs->count < 9) {
      msg = DAT_002d10cc;
    } else {
      msg = b->strs->strs[8];
    }
    FUN_0011e940(DAT_003ea8ec, 0, msg, 0, 0);
    if (DAT_003e1e04 != 0) {
      FUN_000be4b4(DAT_003e1e04);
    }
    break;
  }
  case 7: {
    FUN_00274b9c(self);
    FUN_001c2280(0.1f, 0.5f, DAT_003eaad8);
    self->f51c = 1;
    self->list->v1(1);
    Bar *bar = self->bar;
    Rect *r = *bar->rect;
    short w = r->x1 - r->x0;
    bar->f60 = -w;
    FUN_00108f54(DAT_003ea8ec, 1);
    FUN_00121330(&DAT_003ea8ec->vec, DAT_003ea8ec->vec.size, Tag());
    break;
  }
  case 8:
    self->list->v1(1);
    FUN_0026a46c(self);
    break;
  case 9:
    FUN_000647e0(65535.0f, DAT_003daec4, 10);
    break;
  }
}
}
