/* HSTMATCH module=hstp_trans_main.prx start=0x002400e4 end=0x0024038c symbol=FUN_002400e4 lang=c++ rodata=0x002da1e0 */
/* Clone of src/eboot/state_switch_0022ffe4.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed object and virtual classes, FUN_00048984 returns int (no andi), 0x3eaad8 is the symbol DAT_003eaad8, `if (g) { delete g; g = 0; }` instead of the doubled null test, the range test as `>= 0x28 && < 0x32`; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003eaad8[];
extern void FUN_00108f54(void *, int);
extern void FUN_0016a44c(void *);
extern int FUN_00048984(void);
extern void FUN_0024038c(void *);
extern void FUN_001c0018(void *, int *);
extern void FUN_001c1260(void *);
extern void FUN_001c1338(void *);
extern void FUN_001c142c(void *);
extern void FUN_001c14c4(void *);
extern void FUN_001c15fc(void *, int);
extern void FUN_001c170c(void *, int);
extern void FUN_001c1f44(void *, int);
extern void FUN_001c20b8(void *);
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

extern VD *DAT_003f3b4c;

extern "C" void FUN_002400e4(Obj *o)
{
  switch (o->state) {
  case 1:
    o->f210->m(0);
    if (o->f214 == 0) return;
    FUN_00108f54(o->f214, 0);
    break;
  case 2:
    o->f21c->f4 = 0;
    FUN_0016a44c(o->f21c);
    if (FUN_00048984() == 0) FUN_0024038c(o);
    if (o->f214 != 0) FUN_00108f54(o->f214, 0);
    break;
  case 3:
    FUN_001c20b8(DAT_003eaad8);
    if (o->fa8 >= 0x28 && o->fa8 < 0x32) FUN_001c15fc(DAT_003eaad8, o->fa8 - 0x27);
    FUN_001c170c(DAT_003eaad8, 0);
    FUN_001c170c(DAT_003eaad8, 2);
    FUN_001c170c(DAT_003eaad8, 6);
    FUN_001c14c4(DAT_003eaad8);
    o->fa4 = -1;
    o->fa8 = -1;
    FUN_001c1f44(DAT_003eaad8, 1);
    break;
  case 4:
    if (o->fb0 >= 0) {
      FUN_001c0018(DAT_003eaad8, &o->fb0);
      o->fb0 = -1;
    }
    o->fac = -1;
    o->fb4 = -1;
    FUN_001c1260(DAT_003eaad8);
    FUN_001c1338(DAT_003eaad8);
    FUN_001c142c(DAT_003eaad8);
    FUN_001c1f44(DAT_003eaad8, 1);
    break;
  case 5:
    if (DAT_003f3b4c != 0) {
      delete DAT_003f3b4c;
      DAT_003f3b4c = 0;
    }
    FUN_001c1f44(DAT_003eaad8, 1);
    if (o->f214 != 0) FUN_00108f54(o->f214, 0);
    break;
  case 6:
    o->f210->m(0);
    if (o->f214 != 0) FUN_00108f54(o->f214, 0);
    break;
  case 7:
    o->f210->m(0);
    if (o->f214 != 0) FUN_00108f54(o->f214, 0);
    break;
  case 8:
    o->fb8 = 0;
    o->f210->m(0);
    if (o->f214 != 0) FUN_00108f54(o->f214, 0);
    break;
  }
}
