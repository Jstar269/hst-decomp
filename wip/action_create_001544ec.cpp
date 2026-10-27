/* HSTMATCH module=EBOOT.BIN start=0x001544ec end=0x00154620 symbol=FUN_001544ec lang=c++ */

struct Owner { char pad[8]; int h; unsigned char mode; };

struct Found {
  virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
  virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
  virtual void Reset(int, int);
};

struct Komono {
  virtual void Release(int);
  virtual int Run(int *o, int zero, float f);
  int f4;
};

extern "C" {
extern char DAT_003402f0;
extern int *DAT_0034a114;
extern char DAT_002dc900[];
extern char DAT_002dc904[];
extern char DAT_002dc8e0[];
extern char DAT_003083cc[];
extern char DAT_003088a4[];
int FUN_0014d044(int,int);
void FUN_0014fd94(char *, int, char *);
Found *FUN_001c70c0(int *, int);
void *FUN_00000bcc(int);
}

extern "C" int *FUN_001544ec(Owner *self, int param_2, int param_3, float f12)
{
  Komono *n;
  int r;

  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2,param_2);
    FUN_0014fd94(DAT_002dc8e0, self->h,
                 self->mode != 0 ? DAT_002dc900 : DAT_002dc904);
  }
  Found *f = FUN_001c70c0(DAT_0034a114, self->h);
  if (f != 0) {
    f->Reset(0, 0);
  }
  if (self->mode == 0) {
    return 0;
  }
  n = (Komono *)FUN_00000bcc(8);
  if (n != 0) {
    *(int *)n = (int)DAT_003083cc;
    *(int *)n = (int)DAT_003088a4;
    n->f4 = self->h;
  }
  r = n->Run((int *)param_2, 0, f12);
  if (r != 0) {
    if (n != 0) {
      n->Release(1);
    }
    return 0;
  }
  return (int *)n;
}
// NEAR 43/77 words (0x001544ec). Reproduces the whole shape: the DAT_003402f0 debug block with the
// beqzl string ternary, the FUN_001c70c0 lookup whose vtable+0x28 Reset(0,0) rings t9 from a real
// virtual, the mode==0 early exit, the 8-byte allocation with the two vptr stores and the f4 field,
// the vtable+0xc Run(a1=s0, a2=0, f12=f20) call and the vtable+8 Release(1) failure path.
// What differs: (1) the `mode` early exit branches inverted (ours bnezl over a `b` to the exit,
// retail beqzl straight to the shared exit with `move v0,zero` in the delay); (2) retail computes
// both vptr addresses before storing (v1 then v0) and hoists `lw a0,8(s1)` above them, ours stores
// each as it computes it; (3) retail's tail has three null tests (r, n, n) where ours has two;
// (4) `mov.s f20,f12` sits two slots later.
// Ruled out: `delete n` for the failure path (emits an extra `jal 0xa00` operator delete, 39 words
// but a wrong callee list), `if (n) { n->Release(1); n = 0; }` (81 words), result-variable rewrite
// (81 words). The dtor at 0x00154620 installs __vt__6Komono then __vt__4Base and frees through
// 0x00000a00 when its flag is > 0, which is why the two vptr stores are manual here.
// near miss from lane fm5 (unreviewed)
// improved by lane dsm1 (unreviewed): 43 -> 41 differing words
