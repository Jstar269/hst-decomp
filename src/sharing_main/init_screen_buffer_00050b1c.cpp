/* HSTMATCH module=hstp_trans_main.prx start=0x00050b1c end=0x00050c4c symbol=FUN_00050b1c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2/v0c) corrected by hand: typed owner struct with the mode byte and object pointer past 0x1a000 (lui/addu access), new-then-construct as `mem = alloc(); if (mem) mem = ctor(mem);`, flipped ternary polarity; exact match verified; names and types await human review. */
struct Obj {
  char pad00[0x22];
  unsigned char b22;
};

struct Self {
  char pad00[0x1a0a0];
  unsigned char mode;
  Obj *obj;
};

extern "C" {
extern char DAT_00376980[];
void *FUN_00000bcc(unsigned);
void *FUN_000114c0(void *, int, unsigned);
void *FUN_0004eaf8(void **, void **, int, int, int, int);
void FUN_00050c4c(Self *);
Obj *FUN_000518d4(void *);
void FUN_00051b88(Obj *, char *, void *, int, int);
}

extern "C" void FUN_00050b1c(Self *self, int arg, unsigned flag)
{
  if (self->obj == 0 || self->mode != (flag & 0xff)) {
    FUN_00050c4c(self);
    self->mode = flag;
    void *mem = FUN_00000bcc(0x48);
    if (mem) mem = FUN_000518d4(mem);
    self->obj = (Obj *)mem;
    void *buf = 0;
    void *aux = 0;
    void *surf = FUN_0004eaf8(&buf, &aux, flag != 0 ? 1 : 3, 0, 0x1e0, 0x110);
    int n = self->mode != 0 ? 2 : 4;
    FUN_000114c0(buf, 0, n * 0x1fe00);
    FUN_00051b88(self->obj, DAT_00376980, surf, arg, 0x10);
    self->obj->b22 = 0;
  }
}
