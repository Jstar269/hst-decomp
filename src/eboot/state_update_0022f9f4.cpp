/* HSTMATCH module=EBOOT.BIN start=0x0022f9f4 end=0x0022fc38 symbol=FUN_0022f9f4 lang=c++ rodata=0x002c9bd8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_0034179c[];
extern void *DAT_0034a818;
extern void *DAT_003415d4;
extern void *DAT_003415ac;
extern void FUN_00103128(void *);
extern void FUN_00103628(void *, int);
extern int FUN_001155c0(void *);
extern int FUN_00190724(void *);
extern int FUN_001b1f7c(void *, int);
extern int FUN_001b2bc0(void *, int *);
extern void FUN_001b40d8(void *);
extern void FUN_001b4104(void *);
extern void FUN_0022d49c(void *);
extern void FUN_0022da30(void *);
extern void FUN_0022fcdc(void *, int);
extern void FUN_0023028c(void *);
extern int FUN_002911c0(void *);
extern void FUN_002911cc(void *);
extern void FUN_002a4d40(void *);
}

struct VC { virtual void d0(); virtual void d1(); virtual void m2(); };

struct Bits { signed char a : 2; signed char b : 2; signed char c : 2; };
struct Cfg { char pad[0x8b]; Bits bits; };
extern Cfg *DAT_002cfc8c;

struct Mgr { char pad[0x5d0]; int busy; };
extern Mgr *DAT_0034b350;

struct Obj {
  char pad0[0xac];
  int fac;
  int fb0;
  int fb4;
  unsigned char fb8;
  char pad1[0x214 - 0xb9];
  VC *f214;
  char pad2[0x414 - 0x218];
  int state;
};

extern "C" void FUN_0022f9f4(Obj *o)
{
  FUN_00103128(o);
  switch (o->state) {
  case 0:
    FUN_0023028c(o);
    break;
  case 1:
    FUN_0022da30(o);
    break;
  case 2:
    FUN_0022d49c(o);
    break;
  case 3:
    FUN_0023028c(o);
    break;
  case 4:
    if (FUN_001b1f7c(DAT_0034179c, o->fb0) == 0 && o->fac >= 0) {
      int r = FUN_001b2bc0(DAT_0034179c, &o->fac);
      o->fb0 = r;
      if (r < 0) {
        o->fac = -1;
        FUN_0022fcdc(o, 0);
      }
    }
    FUN_0023028c(o);
    break;
  case 5:
    if (FUN_002911c0(DAT_0034a818) == 0 || DAT_002cfc8c->bits.b == 0 || DAT_002cfc8c->bits.c == 0) {
      FUN_002911cc(DAT_0034a818);
      FUN_0022fcdc(o, 0);
    }
    break;
  case 6:
    if (FUN_00190724(DAT_003415d4) != 0) FUN_0022fcdc(o, 0);
    break;
  case 7:
    if (FUN_00190724(DAT_003415d4) != 0) FUN_0022fcdc(o, 0);
    break;
  case 8:
    if (o->fb8 != 0) {
      if (FUN_001155c0(DAT_003415ac) != 0) {
        FUN_00103628(DAT_003415ac, 1);
        FUN_002a4d40(DAT_0034b350);
        o->fb8 = 0;
        FUN_001b40d8(DAT_0034179c);
      }
    } else {
      if (DAT_0034b350 != 0 && DAT_0034b350->busy == 0) {
        FUN_001b4104(DAT_0034179c);
        FUN_0022fcdc(o, 0);
      }
    }
    break;
  }
  if (o->f214 != 0) o->f214->m2();
}
