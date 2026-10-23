/* HSTMATCH module=EBOOT.BIN start=0x00098870 end=0x00098a0c symbol=FUN_00098870 lang=c++ */
/* NEAR MISS 101/103 words, 51 differing: loop 1 (packet/handle release) matches exactly, the virtual call
   matches, but the second loop's registers are permuted (ours tab=s2/j=s1/i=s3, retail tab=s1/j=s2/i=s0) and
   retail keeps a dead `*(int*)(self+0x5c4)` load plus a `subu v1,v1,v1` zero store. */
extern "C" int DAT_003386b0;
extern "C" char DAT_002beb78[];
extern "C" int DAT_00338770;
extern "C" int DAT_00338774[];

extern "C" void FUN_001b5594(int, int);
extern "C" int FUN_00093024(int);
extern "C" void FUN_0009306c(int);
extern "C" void FUN_00057730(void *);
extern "C" int FUN_00055e48(int, int);
extern "C" void FUN_000009e4(void);

struct Disp {
  virtual void f0();
  virtual void f1();
  virtual void f2();
  virtual void f3();
  virtual void f4();
};

struct Obj {
  char pad0[0x148];
  int f148;
  char pad1[0x5bc - 0x14c];
  int f5bc;
  int f5c0;
  int f5c4;
  char pad2[8];
  Disp disp;
};

struct False {};

extern "C" void FUN_00098870(Obj *self, False)
{
  unsigned int n;
  int j;
  int i;
  int flag;
  char *ent;
  int off;
  int **tab;

  if (DAT_003386b0 != 0 && *(int *)(DAT_003386b0 + 0xa8) != 0)
    FUN_001b5594(*(int *)(DAT_003386b0 + 0xa8), self->f148);

  flag = FUN_00093024(self->f5bc) != 0;
  FUN_0009306c(self->f5bc);
  FUN_00057730(&self->disp);
  self->disp.f3();

  n = 0;
  if (self->f5c4 != 0) {
    ent = DAT_002beb78;
    off = 0;
    do {
      if (ent[1] != 0) {
        *(int *)(self->f5c0 + off) = 0;
      } else if (*(int *)(self->f5c0 + off) != 0) {
        FUN_00055e48(*(int *)(self->f5c0 + off), 1);
        *(int *)(self->f5c0 + off) = 0;
      }
      n++;
      ent += 0x10;
      off += 4;
    } while (n < (unsigned int)self->f5c4);
  }
  self->f5c4 = 0;

  if (flag != 0 && --DAT_00338770 == 0) {
    n = 0;
    tab = (int **)DAT_00338774;
    do {
      j = 0;
      i = 0;
      do {
        if (*(int *)((char *)*tab + i) != 0) {
          FUN_00055e48(*(int *)((char *)*tab + i), 1);
          *(int *)((char *)*tab + i) = 0;
        }
        j++;
        i += 4;
      } while (j < 0x115);
      if (*tab != 0) {
        FUN_000009e4();
        *tab = 0;
      }
      n++;
      tab++;
    } while (n < 2);
  }
}
// near miss from lane fm7 (unreviewed)
