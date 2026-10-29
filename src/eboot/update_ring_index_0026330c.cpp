/* HSTMATCH module=EBOOT.BIN start=0x0026330c end=0x0026348c symbol=FUN_0026330c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Virtual slot 8 gates the update: advance the 32-entry ring index at +0x1864 (signed % RING_SIZE), store base + index into the record at +0x1860, and when FUN_00262c14 returns 0 run the follow-up calls, show the string chosen from table entry 18 and bump the counter at +0x1858. */
#include "hst/screen_obj.h"

/* Virtual interface of the screen object (slot 8 reports whether the update may run). */
struct ScreenVt {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
  virtual void s4();
  virtual void s5();
  virtual void s6();
  virtual void s7();
  virtual int s8();
};
struct Inner8 {
  char pad[8];
  int total;       /* 0x8 */
};
struct InnerC {
  char pad[0x228];
  const char **lines;  /* 0x228 */
  int count;           /* 0x22c */
};
/* Message-table entry returned by FUN_0018c9f4 (see FUN_00263d20). */
struct Ent {
  int unk0;
  int loaded;      /* 0x4, zero when missing */
  Inner8 *counts;  /* 0x8 */
  InnerC *list;    /* 0xc */
};
struct Sink {
  virtual void s0();
  virtual void s1();
  virtual void s2();
};

enum { TEXT_ENTRY_ID = 18 }; /* entry looked up in the message table */

extern char DAT_002c0e18[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e20[];
extern int DAT_003386c8;
extern ScreenEnv *DAT_00338ac4;
extern "C" {
Sink *FUN_0008d994(int);
void FUN_00103128(ScreenObj *);
void FUN_00103628(Sink *, int);
void FUN_00110a78(Sink *, const char *, int);
Ent *FUN_0018c9f4(int);
void FUN_00258630(ScreenObj *, int);
void FUN_00258a68(ScreenObj *);
void FUN_0025967c(ScreenObj *);
int FUN_00262c14(ScreenObj *);
}

/* Advance the ring index and, when the helper returns 0, run the follow-up calls, show the table message and count the update. */
extern "C" void FUN_0026330c(ScreenObj *self)
{
  if (!((ScreenVt *)self)->s8())
    return;
  FUN_00103128(self);
  int index = (self->ring_index + 1) % RING_SIZE;
  self->ring_index = index;
  self->ring->unk24 = self->ring->unk28 + index;
  if (FUN_00262c14(self) == 0) {
    FUN_00258630(self, 0);
    FUN_00258a68(self);
    int ok = 1;
    if (DAT_00338ac4 != 0 && DAT_00338ac4->unk178 == 0)
      ok = 0;
    if (ok == 0)
      FUN_0025967c(self);
    Ent *e = FUN_0018c9f4(TEXT_ENTRY_ID);
    const char *s;
    if (e->loaded == 0)
      s = DAT_002c0e20;
    else if (e->counts->total < 47)
      s = DAT_002c0e1c;
    else if (e->list->count < 1)
      s = DAT_002c0e18;
    else
      s = *e->list->lines;
    FUN_00110a78(FUN_0008d994(DAT_003386c8), s, 0);
    FUN_00103628(FUN_0008d994(DAT_003386c8), 0);
    FUN_0008d994(DAT_003386c8)->s2();
    self->unk1858++;
  }
}
