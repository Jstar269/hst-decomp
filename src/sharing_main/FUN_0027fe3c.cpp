/* HSTMATCH module=hstp_trans_main.prx start=0x0027fe3c end=0x0027ff44 symbol=FUN_0027fe3c lang=c++ */
/* Clone of src/eboot/FUN_0026edfc.cpp (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: reconstructed C++ virtual call, materialised bool flag condition, supplied DAT_003e1a08 to FUN_0008f170; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_003e1a08;
extern int *DAT_003f4830[];
extern int DAT_003f48d0;
extern void *FUN_0008f170(void *);
extern void FUN_00108f54(void *, int);
extern void FUN_0023212c(void *, int *, int);
extern void FUN_0027e63c(void *, int);
extern void FUN_002bd1a4();
}

struct TargetSub {
  char pad[0x78];
  float f78;
};

struct Target {
  virtual void d0();
  virtual void d1();
  virtual void call10();
  char pad[0x60 - 4];
  int f60;
  int pad2;
  TargetSub *f68;
};

struct Obj {
  char pad0[0x108];
  int f108;
  char pad1[0x8cc - 0x10c];
  unsigned char f8cc;
  char pad2[0xa08 - 0x8cd];
  int f2568;
  Target *f2572;
  int f2576;
};

extern "C" void FUN_0027fe3c(Obj *self)
{
  if (self->f2568 == 0) {
    FUN_0023212c(self->f2572, DAT_003f4830[self->f2576], 1);
    self->f2576++;
    self->f2568++;
  }
  else {
    Target *t = self->f2572;
    bool b = t->f60 < 0 || t->f68->f78 <= 0.0f;
    if (b) {
      if (self->f2576 < DAT_003f48d0) {
        self->f2568 = 0;
      }
      else {
        self->f2576 = 0;
        FUN_0027e63c(self, self->f108);
        self->f8cc = 1;
        FUN_002bd1a4();
        void *p = FUN_0008f170(DAT_003e1a08);
        FUN_00108f54(p, 0);
      }
    }
  }
  self->f2572->call10();
}
