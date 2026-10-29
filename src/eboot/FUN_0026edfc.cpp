/* HSTMATCH module=EBOOT.BIN start=0x0026edfc end=0x0026ef04 symbol=FUN_0026edfc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: reconstructed C++ virtual call, materialised bool flag condition, supplied DAT_003386c8 to FUN_0008d994; readability pass; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_003386c8;
extern int *DAT_0034b4f0[];
extern int DAT_0034b590;
extern void *FUN_0008d994(void *);
extern void FUN_00103628(void *, int);
extern void FUN_00222bb8(void *, int *, int);
extern void FUN_0026d5fc(void *, int);
extern void FUN_002ad9e8();
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
  int phase;       /* 0xa08 0 = start the next item, else wait for the target to finish */
  Target *target;   /* 0xa0c */
  int index;       /* 0xa10 next row of the global table */
};

extern "C" void FUN_0026edfc(Obj *self)
{
  if (self->phase == 0) {
    FUN_00222bb8(self->target, DAT_0034b4f0[self->index], 1);
    self->index++;
    self->phase++;
  }
  else {
    Target *t = self->target; /* current target */
    bool b = t->f60 < 0 || t->f68->f78 <= 0.0f;
    if (b) {
      if (self->index < DAT_0034b590) {
        self->phase = 0;
      }
      else {
        self->index = 0;
        FUN_0026d5fc(self, self->f108);
        self->f8cc = 1;
        FUN_002ad9e8();
        void *p = FUN_0008d994(DAT_003386c8);
        FUN_00103628(p, 0);
      }
    }
  }
  self->target->call10();
}
