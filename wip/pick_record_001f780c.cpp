/* HSTMATCH module=EBOOT.BIN start=0x001f780c end=0x001f7b6c symbol=FUN_001f780c lang=c++ */
struct Rec {
  unsigned char used;
  char pad1[3];
  int start;
  int len;
  int kind;
  int idx;
};
struct Slot2 {
  unsigned char v;
  unsigned char pad;
};
struct Tables {
  char pad0[0x34c];
  Slot2 t4[640];
  unsigned char t1[640];
  unsigned char t2[640];
  unsigned char t3[640];
};
struct Obj {
  char pad0[0x3d4];
  int f3d4;
  char pad1[0x524 - 0x3d8];
  int f524;
  char pad2[0x59d - 0x528];
  unsigned char b59d;
  char pad3[0x5b1 - 0x59e];
  unsigned char b5b1;
  char pad4[0x136c - 0x5b2];
  Rec recs2[0x180 / 1];
};

extern "C" {
extern int DAT_0034a678;
extern int DAT_00310fc8;
extern unsigned char DAT_00341834[];
extern unsigned char DAT_00341c7a;
Tables *FUN_0016bb88(void);
int FUN_0022c1c4(void);
int FUN_001f76e4(Obj *, Rec *, int, int);
void FUN_001fabb4(Obj *, int, int, int);
}

static inline unsigned char *P1(Tables *t, int i) { if (i >= 0 && i < 640) return &t->t1[i]; return 0; }
static inline unsigned char *P2(Tables *t, int i) { if (i >= 0 && i < 640) return &t->t2[i]; return 0; }
static inline unsigned char *P3(Tables *t, int i) { if (i >= 0 && i < 640) return &t->t3[i]; return 0; }
static inline unsigned char *P4(Tables *t, int i) { if (i >= 0 && i < 640) return &t->t4[i].v; return 0; }

extern "C" void FUN_001f780c(Obj *self, int force)
{
  Tables *tab;
  Rec *rec;
  int kb;
  int i;
  int r;
  unsigned char ok;
  if (force != 0 || DAT_0034a678 == 0x2a || DAT_0034a678 == 0x31) {
    tab = FUN_0016bb88();
    kb = DAT_00341834[self->f3d4 * 0x120];
    ok = 0;
    rec = (Rec *)((char *)self + 0x776c);
    if (self->b5b1 != 0) {
      if (DAT_00341c7a != 2) {
        int n = FUN_0022c1c4();
        rec = (Rec *)((char *)self + n * 0xa00 + 0x136c);
        ok = FUN_001f76e4(self, rec, kb, self->f524);
      }
    } else {
      ok = FUN_001f76e4(self, rec, kb, self->f524);
    }
    if (ok != 0) {
      int total = 0;
      int c;
      Rec *q = rec;
      for (c = 0; c < 128; c++) {
        total += q->len;
        q++;
      }
      DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
      r = (int)(((unsigned)DAT_00310fc8 >> 16) & 0x7fff) % total;
      if (force != 0)
        r = 0;
      i = 0;
      do {
        if (rec->used != 0 && rec->start <= r && r < rec->start + rec->len) {
          int flag = 0;
          switch (rec->kind) {
          case 1:
            if (*P1(tab, rec->idx) - 4U > 1)
              flag = 1;
            break;
          case 2:
            if (*P2(tab, rec->idx) - 4U > 1)
              flag = 1;
            break;
          case 3:
            if (*P3(tab, rec->idx) - 4U > 1)
              flag = 1;
            break;
          case 4:
            if (*P4(tab, rec->idx) - 4U > 1)
              flag = 1;
            break;
          }
          if (flag) {
            FUN_001fabb4(self, rec->kind, rec->idx, 1);
            self->b59d = 1;
          }
        }
        i++;
        rec++;
      } while (i < 128);
    }
  }
}
// NOT MATCHED (216/216 words, 17 blocks differ, all register colouring; every instruction shape is right): retail uses six saved
// registers (force s5, r s4, kb/i s3, tab s2, self s1, rec s0, `i` reusing kb's s3 while r keeps its own s4), ours five (force's s4 is
// reused for the loop counter, r shares kb's s3). All 120 declaration orders of {kb, tab, rec, r, i} give the same 92 differing words,
// one variable for kb and i, and local-vs-up-front declarations did not change the colouring either.
// Solved on the way: bounds accessor `if (i >= 0 && i < 640) return &t[i]; return 0;` (the early-return `i < 0` form flips the
// bltzl/bgezl shape), kinds as a `switch` with cases 1..4 in source order (tests come out 4,3,2,1), the b5b1 != 0 arm first,
// 8x-unrolled sum loop as a plain `for (c = 0; c < 128; c++) total += q->len; q++`, `ext` from `((unsigned)G >> 16) & 0x7fff` modulo total.
// near miss from lane sn4 (unreviewed)
