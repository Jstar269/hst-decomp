/* HSTMATCH module=EBOOT.BIN start=0x0001c104 end=0x0001c1fc symbol=FUN_0001c104 lang=c++ */
struct Obj {
  int f0;
  int f4;
  int f8;
  int fc;
  int f10;
  int f14;
  int f18;
  char pad[0x4024 - 0x1c];
  unsigned char f4024;
  char pad2[7];
  void (*f402c)();
};

extern "C" int DAT_002cfae4;
extern "C" int DAT_0030ebd4;
extern "C" unsigned char DAT_0030ebd8;
extern "C" char DAT_002cfc24[];

extern "C" void FUN_000104e0();
extern "C" void FUN_002b78f0();
extern "C" void FUN_002b7958(int);
extern "C" void FUN_0001b918(const char *);

extern "C" void FUN_0001c104(Obj *self)
{
  if (DAT_002cfae4 != 4) {
    if (self->f0 != 0) {
      if (self->f4024 == 0) {
        DAT_0030ebd8 = 1;
        if (DAT_0030ebd4 > 0) {
          do {
            FUN_002b78f0();
            FUN_002b7958(100);
          } while (DAT_0030ebd4 > 0);
        }
        void (*fn)() = self->f402c;
        if (self->f0 != self->f18) {
          FUN_000104e0();
          fn = self->f402c;
        }
        if (fn != 0) {
          fn();
        }
        FUN_0001b918(DAT_002cfc24);
      }
    }
  } else {
    if (self->f0 != 0) {
      FUN_000104e0();
    }
  }
  self->f0 = 0;
  self->f4 = 0;
  self->f8 = 0;
  self->fc = -1;
  self->f10 = 0;
  self->f14 = 0;
  self->f4024 = 0;
}
// NEAR MISS: 124/124 words, 19 differ (all register allocation).
// The whole temp pool is shifted: retail uses v1 for addresses and a0 for values
// (and never v0), ours uses v0 for addresses and v1 for values; the function-pointer
// target likewise: retail `jalr v1` (in v1), ours `jalr a0` (in a0).
// The control flow matches exactly (the `if (DAT_002cfae4 != 4) {main} else {...}` inversion
// gives retail's beql target and the ra reload in the beqzl delay slot).
// Ruled out: plain C (lang=c99) with the same shape, pointer vs int types for f0/f18, an
// inline getter, a mode local, moving the fn declaration, and the `f0 == 0` / `f4024 != 0`
// inversions.
// near miss from lane om1 (unreviewed)
