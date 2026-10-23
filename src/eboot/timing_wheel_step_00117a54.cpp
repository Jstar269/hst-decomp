/* HSTMATCH module=EBOOT.BIN start=0x00117a54 end=0x00117c24 symbol=FUN_00117a54 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The nine-slot expiry is a real C++ virtual call (a function-pointer call compiles to `lw v0,slot; jalr v0`,
   retail has `lw t9`), the latch test is written as one condition (`f < 0 && -f <= f58`) which is what puts the
   negation before the field load, and the two stack temporaries must be declared `b` before `a` to land in
   retail's slots (0x2c/0x28). */
extern void *DAT_003386b0;

class Obj {
public:
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
};

typedef struct Mgr {
  char pad0[0x88];
  Obj *f88;
} Mgr;

typedef struct Slot {
  char pad0[0x38];
  int f38;
  char pad1[0x40 - 0x3c];
  int f40;
  char pad2[0x70 - 0x44];
} Slot;

typedef struct State {
  char pad0[0x50];
  int f50;
  int f54;
  int f58;
  int f5c;
  int f60;
  int f64;
  int f68;
  int f6c;
  int f70;
  char pad1[0x80 - 0x74];
  Slot slots[9];
} State;

extern "C" void FUN_0001f558(void *, int, int, int);
extern "C" void FUN_001180b0(State *, Slot *, int);
extern "C" void FUN_0008ac88(void *);

extern "C" void FUN_00117a54(State *self)
{
  int notify;
  int i;
  int idx;
  int n;
  int f;
  int b;
  int a;
  int *p;
  Slot *e;
  Obj *o;
  int j;

  notify = 0;
  if (self->f60 < 0)
    goto set_notify;
  {
    if (self->f58 == self->f50)
      FUN_0001f558(DAT_003386b0, 0x14, 0, 0);
    i = self->f68;
    idx = (i + 1) % 9;
    e = &self->slots[idx];
    if (e->f38 >= 0) {
      if (self->f58 >= e->f38) {
        FUN_001180b0(self, e, 1);
        o = ((Mgr *)DAT_003386b0)->f88;
        n = self->f58 - e->f38;
        for (j = 0; j < n; j++)
          o->v10();
        self->f68 = idx;
        self->f70 = n - 1;
        i = self->f68;
        e = &self->slots[(i + 1) % 9];
      }
    }
    f = e->f38;
    if (f < 0 && -f <= self->f58)
      notify = 1;
    a = self->slots[i].f40 - 1;
    b = self->f70 + 1;
    p = (a < b) ? &a : &b;
    self->f70 = *p;
    self->f58 = self->f58 + 1;
  }
  goto tail;
set_notify:
  notify = 1;
tail:
  if (notify)
    FUN_0008ac88(DAT_003386b0);
}
