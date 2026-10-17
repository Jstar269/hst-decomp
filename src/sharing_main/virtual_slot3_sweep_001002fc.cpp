/* HSTMATCH module=hstp_trans_main.prx start=0x001002fc end=0x0010052c symbol=FUN_001002fc lang=c++ */
/* Clone of src/eboot/virtual_slot3_sweep_000fabc0.cpp (hstclone.py tag s10170158a4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* When the byte at +0x155 is set and the game state word (+0x3c of DAT_003e19f0) is neither 9 nor 2 (or there is no game), calls 0x1ed06c with the pointer at +0x94; otherwise, if bit 0x800 of DAT_0037c440 is set, calls virtual slot 3 (vtable +20) on a run of member objects (some null-checked, two gated on a float at +0x78 of the object at +0x9c / +0xbc), then 0xf293c, 0xf2bf4, slot 2 of the object at +0x88, 0xf6c48 twice, and in state 6 with DAT_003e1e84+0xa0 below 2 calls 0x1eab70. Matching idioms: the else branch holds the long body (retail lays the 0x1ed06c arm out first), the state test is a one-case switch. */
struct VC {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
};
struct Mid {
  char pad[0x78];
  float f78;
};
struct Top : VC {
  char pad[0x1b4];
  VC *f1b8;
};
struct Obj {
  char pad0[0x54];
  Top *f54;
  VC *f58;
  VC *f5c;
  VC *f60;
  VC *f64;
  VC *f68;
  VC *f6c;
  VC *f70;
  VC *f74;
  VC *f78;
  void *f7c;
  void *f80;
  VC *f84;
  VC *f88;
  void *f8c;
  void *f90;
  void *f94;
  void *f98;
  Mid *f9c;
  char pad1[0x1c];
  Mid *fbc;
  char pad2[0x95];
  unsigned char f155;
};
struct GameA { char pad[0x3c]; int f3c; };
struct GameB { char pad[0xa0]; unsigned fa0; };
extern int DAT_0037c440;
extern GameA *DAT_003e19f0;
extern GameB *DAT_003e1e84;
extern "C" void FUN_000f8004(void *);
extern "C" void FUN_000f82bc(void *);
extern "C" void FUN_000fc33c(void *);
extern "C" void FUN_001f8e14(void *);
extern "C" void FUN_001fb3dc(void *);

extern "C" void FUN_001002fc(Obj *o)
{
  if (o->f155 != 0 && (DAT_003e19f0 == 0 || (DAT_003e19f0->f3c != 9 && DAT_003e19f0->f3c != 2))) {
    FUN_001fb3dc(o->f94);
  } else {
    if ((DAT_0037c440 & 0x800) != 0) {
      o->f58->s3();
      if (o->f5c != 0) o->f5c->s3();
      if (o->f60 != 0) o->f60->s3();
      if (o->f64 != 0) o->f64->s3();
      o->f68->s3();
      if (o->f9c->f78 > 0.0f) o->f54->s3();
      if (o->fbc->f78 > 0.0f) o->f54->f1b8->s3();
      o->f84->s3();
      o->f70->s3();
      o->f6c->s3();
      o->f74->s3();
      o->f78->s3();
      FUN_000f8004(o->f7c);
      FUN_000f82bc(o->f80);
      o->f88->s2();
      FUN_000fc33c(o->f8c);
      FUN_000fc33c(o->f90);
      switch (DAT_003e19f0->f3c) {
      case 6:
        if (DAT_003e1e84->fa0 < 2) {
          FUN_001f8e14(o->f98);
        }
        break;
      }
    }
  }
}
