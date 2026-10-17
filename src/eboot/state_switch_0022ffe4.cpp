/* HSTMATCH module=EBOOT.BIN start=0x0022ffe4 end=0x0023028c symbol=FUN_0022ffe4 lang=c++ rodata=0x002c9c20 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed object and virtual classes, FUN_000487f4 returns int (no andi), 0x34179c is the symbol DAT_0034179c, `if (g) { delete g; g = 0; }` instead of the doubled null test, the range test as `>= 0x28 && < 0x32`; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_0034179c[];
extern void FUN_00103628(void *, int);
extern void FUN_0015dec0(void *);
extern int FUN_000487f4(void);
extern void FUN_0023028c(void *);
extern void FUN_001b1f84(void *, int *);
extern void FUN_001b3130(void *);
extern void FUN_001b3140(void *);
extern void FUN_001b31ac(void *);
extern void FUN_001b3244(void *);
extern void FUN_001b32f8(void *, int);
extern void FUN_001b338c(void *, int);
extern void FUN_001b3ce8(void *, int);
extern void FUN_001b3e2c(void *);
}

struct VC { virtual void d0(); virtual void m(int); };
struct VD { virtual ~VD(); };

struct Sub { char pad[4]; unsigned char f4; };

struct Obj {
  char pad0[0xa4];
  int fa4;
  int fa8;
  int fac;
  int fb0;
  int fb4;
  unsigned char fb8;
  char pad1[0x210 - 0xb9];
  VC *f210;
  void *f214;
  char pad2[4];
  Sub *f21c;
  char pad3[0x414 - 0x220];
  int state;
};

extern VD *DAT_0034a81c;

extern "C" void FUN_0022ffe4(Obj *o)
{
  switch (o->state) {
  case 1:
    o->f210->m(0);
    if (o->f214 == 0) return;
    FUN_00103628(o->f214, 0);
    break;
  case 2:
    o->f21c->f4 = 0;
    FUN_0015dec0(o->f21c);
    if (FUN_000487f4() == 0) FUN_0023028c(o);
    if (o->f214 != 0) FUN_00103628(o->f214, 0);
    break;
  case 3:
    FUN_001b3e2c(DAT_0034179c);
    if (o->fa8 >= 0x28 && o->fa8 < 0x32) FUN_001b32f8(DAT_0034179c, o->fa8 - 0x27);
    FUN_001b338c(DAT_0034179c, 0);
    FUN_001b338c(DAT_0034179c, 2);
    FUN_001b338c(DAT_0034179c, 6);
    FUN_001b3244(DAT_0034179c);
    o->fa4 = -1;
    o->fa8 = -1;
    FUN_001b3ce8(DAT_0034179c, 1);
    break;
  case 4:
    if (o->fb0 >= 0) {
      FUN_001b1f84(DAT_0034179c, &o->fb0);
      o->fb0 = -1;
    }
    o->fac = -1;
    o->fb4 = -1;
    FUN_001b3130(DAT_0034179c);
    FUN_001b3140(DAT_0034179c);
    FUN_001b31ac(DAT_0034179c);
    FUN_001b3ce8(DAT_0034179c, 1);
    break;
  case 5:
    if (DAT_0034a81c != 0) {
      delete DAT_0034a81c;
      DAT_0034a81c = 0;
    }
    FUN_001b3ce8(DAT_0034179c, 1);
    if (o->f214 != 0) FUN_00103628(o->f214, 0);
    break;
  case 6:
    o->f210->m(0);
    if (o->f214 != 0) FUN_00103628(o->f214, 0);
    break;
  case 7:
    o->f210->m(0);
    if (o->f214 != 0) FUN_00103628(o->f214, 0);
    break;
  case 8:
    o->fb8 = 0;
    o->f210->m(0);
    if (o->f214 != 0) FUN_00103628(o->f214, 0);
    break;
  }
}
