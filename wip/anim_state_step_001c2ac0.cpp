/* HSTMATCH module=EBOOT.BIN start=0x001c2ac0 end=0x001c2cc4 symbol=FUN_001c2ac0 lang=c++ */
/* NEAR MISS 130/129 words, 93 differ. Everything up to 0x1c2b5c matches: the f08<f6c guard, the two-test
   flag block (retail keeps the second load in the bnezl delay slot), the 0x10 virtual call and the f5c guard.
   Remaining deltas: (1) retail materialises b2 as `sltiu s2,(x==1),1` and then RE-normalises it with
   `sltu v0,zero,s2` before `beqzl v0`, where ours branches on s2 directly (1 extra word + a dead `move v0,zero`
   in the delay slot); (2) b3 in retail is `sltu v0,zero,v0; xori v0,v0,0x1` (= `!FUN_001cd2a8(...)`), which the
   `!` spelling here does not reproduce in place; (3) retail passes FUN_00127ac0 the truncated pointer
   (`andi s1,v0,0xff` off the same call's return) - the same shape appears in our build, but one word later. */

struct V {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void *v6();
  virtual void v7(void *);
};

extern V *DAT_0033b580;
extern void *DAT_002ea2f0;
extern V *DAT_0034a114;

extern "C" void FUN_0012de6c(V *, int, int, int);
extern "C" void FUN_0018a960(int, int, int);
extern "C" void FUN_001c25b0(char *, int, int, void *, char *);
extern "C" void FUN_001cd88c(char *, int, int);
extern "C" int FUN_001cd2a8(V *);
extern "C" void FUN_00127ac0(void *, bool);
extern "C" void FUN_00127d5c(void *, bool);
extern "C" void *FUN_00288a84(int);

extern "C" void FUN_001c2ac0(char *self)
{
  void *r;
  bool b2;
  bool b3;

  if (*(int *)(self + 8) < *(int *)(self + 0x6c))
    return;
  if (*(unsigned char *)(self + 99) == 0) {
    FUN_0018a960(*(int *)(self + 0x20), *(int *)(self + 0x68), 1);
    *(unsigned char *)(self + 99) = 1;
    *(int *)(self + 0x6c) = -1;
  }
  if (*(unsigned char *)(self + 99) == 0)
    return;
  (*(V **)(self + 0x20))->v2();
  if (*(int *)(self + 0x5c) != 0) {
    r = FUN_00288a84(*(int *)(self + 0x5c));
    if (r != 0) {
      b2 = *(int *)(*(int *)(self + 0x20) + 0x54) == 1;
      if (b2)
        b3 = FUN_001cd2a8(DAT_0034a114) == 0;
      else
        b3 = false;
      FUN_00127ac0(FUN_00288a84(*(int *)(self + 0x5c)), b3);
      FUN_00127d5c(FUN_00288a84(*(int *)(self + 0x5c)), b2);
    }
  }
  if (*(int *)(*(int *)(self + 0x20) + 0x54) == 4 && *(int *)(self + 0x70) < 1) {
    *(int *)(self + 0x5c) = 0;
    if (*(int *)(self + 0x74) < 0) {
      FUN_001cd88c(self, 0, 1);
    } else {
      FUN_001c25b0(self, *(int *)(self + 0x74), *(int *)(self + 0x78), DAT_002ea2f0,
                   self + 0x80);
      *(int *)(self + 0x74) = -1;
      *(int *)(self + 0x78) = -1;
    }
    *(char *)(self + 99) = 0;
  } else {
    if (*(int *)(*(int *)(self + 0x20) + 0x54) == 4)
      *(int *)(self + 0x70) = *(int *)(self + 0x70) - 1;
    if (*(char *)(self + 100) == 0 && *(char *)(self + 0x65) == 0 &&
        *(int *)(self + 0x5c) != 0 && DAT_0033b580 != 0 && *(char *)(self + 0x60) == 0) {
      FUN_0012de6c(DAT_0033b580, 1, 0, 0);
      r = (*(V **)(self + 0x5c))->v6();
      DAT_0033b580->v7(r);
    }
  }
}
// near miss from lane fm7 (unreviewed)
