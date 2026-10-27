/* HSTMATCH module=hstp_trans_main.prx start=0x0023faf4 end=0x0023fd38 symbol=FUN_0023faf4 lang=c++ rodata=0x002da198 */
/* Clone of src/eboot/state_update_0022f9f4.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003eaad8[];
extern void *DAT_003f3b48;
extern void *DAT_003ea914;
extern void *DAT_003ea8ec;
extern void FUN_00108a2c(void *);
extern void FUN_00108f54(void *, int);
extern int FUN_001204dc(void *);
extern int FUN_0019cf34(void *);
extern int FUN_001c0010(void *, int);
extern int FUN_001c0cf0(void *, int *);
extern void FUN_001c221c(void *);
extern void FUN_001c2248(void *);
extern void FUN_0023d59c(void *);
extern void FUN_0023db30(void *);
extern void FUN_0023fddc(void *, int);
extern void FUN_0024038c(void *);
extern int FUN_002a28c8(void *);
extern void FUN_002a28d4(void *);
extern void FUN_002b44d0(void *);
}

struct VC { virtual void d0(); virtual void d1(); virtual void m2(); };

struct Bits { signed char a : 2; signed char b : 2; signed char c : 2; };
struct Cfg { char pad[0x8b]; Bits bits; };
extern Cfg *DAT_003751d4;

struct Mgr { char pad[0x5d0]; int busy; };
extern Mgr *DAT_003f469c;

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

extern "C" void FUN_0023faf4(Obj *o)
{
  FUN_00108a2c(o);
  switch (o->state) {
  case 0:
    FUN_0024038c(o);
    break;
  case 1:
    FUN_0023db30(o);
    break;
  case 2:
    FUN_0023d59c(o);
    break;
  case 3:
    FUN_0024038c(o);
    break;
  case 4:
    if (FUN_001c0010(DAT_003eaad8, o->fb0) == 0 && o->fac >= 0) {
      int r = FUN_001c0cf0(DAT_003eaad8, &o->fac);
      o->fb0 = r;
      if (r < 0) {
        o->fac = -1;
        FUN_0023fddc(o, 0);
      }
    }
    FUN_0024038c(o);
    break;
  case 5:
    if (FUN_002a28c8(DAT_003f3b48) == 0 || DAT_003751d4->bits.b == 0 || DAT_003751d4->bits.c == 0) {
      FUN_002a28d4(DAT_003f3b48);
      FUN_0023fddc(o, 0);
    }
    break;
  case 6:
    if (FUN_0019cf34(DAT_003ea914) != 0) FUN_0023fddc(o, 0);
    break;
  case 7:
    if (FUN_0019cf34(DAT_003ea914) != 0) FUN_0023fddc(o, 0);
    break;
  case 8:
    if (o->fb8 != 0) {
      if (FUN_001204dc(DAT_003ea8ec) != 0) {
        FUN_00108f54(DAT_003ea8ec, 1);
        FUN_002b44d0(DAT_003f469c);
        o->fb8 = 0;
        FUN_001c221c(DAT_003eaad8);
      }
    } else {
      if (DAT_003f469c != 0 && DAT_003f469c->busy == 0) {
        FUN_001c2248(DAT_003eaad8);
        FUN_0023fddc(o, 0);
      }
    }
    break;
  }
  if (o->f214 != 0) o->f214->m2();
}
