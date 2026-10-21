/* HSTMATCH module=EBOOT.BIN start=0x00127dc4 end=0x00128138 symbol=FUN_00127dc4 lang=c++ */
/* Hand-written reconstruction from the disassembly (Ghidra tag a1 pseudocode as the guide); exact match verified (matching idioms: the 18-way inequality chain is a materialised flag 'ok = v != G0; if (ok) ok = v != G1; ...', the pseudo-random draw is '(h >> 16) & 0x7fff' on an unsigned so MWCC emits ext, and the clamp between two int globals is an inline ClampI(float, const int&, const int&) with 'v < lo ? lo : (!(v > hi) ? v : hi)'); names and types await human review. */
struct Item {
  char pad0[0xf0];
  int f240;
  char pad1[0x124 - 0xf4];
  int f292;
};
struct Obj {
  char pad0[0x58];
  Item *f58;
  char pad1[0x344 - 0x5c];
  int f836;
};

extern "C" {
extern int DAT_0034a114;
extern int DAT_0033b4f0[18];
extern int DAT_002da8f0;
extern int DAT_002da8f4;
int FUN_001cd2a8(int);
int FUN_001c6cac(int);
int FUN_0012b760(Obj *);
int FUN_0012b7cc(Obj *);
unsigned FUN_0001342c();
void FUN_0012b470(Obj *, int, int);
void FUN_001281e8(Obj *);
void FUN_0012b2b0(float, Obj *, int, int);
}

static inline float ClampI(float v, const int &lo, const int &hi)
{
  return v < (float)lo ? (float)lo : (!(v > (float)hi) ? v : (float)hi);
}

extern "C" void FUN_00127dc4(Obj *self)
{
  if (FUN_001cd2a8(DAT_0034a114) == 0)
    return;
  Item *it = self->f58;
  if (it == 0)
    return;
  int v = it->f240;
  {
    int ok = v != DAT_0033b4f0[0];
    if (ok) ok = v != DAT_0033b4f0[1];
    if (ok) ok = v != DAT_0033b4f0[2];
    if (ok) ok = v != DAT_0033b4f0[3];
    if (ok) ok = v != DAT_0033b4f0[4];
    if (ok) ok = v != DAT_0033b4f0[5];
    if (ok) ok = v != DAT_0033b4f0[6];
    if (ok) ok = v != DAT_0033b4f0[7];
    if (ok) ok = v != DAT_0033b4f0[8];
    if (ok) ok = v != DAT_0033b4f0[9];
    if (ok) ok = v != DAT_0033b4f0[10];
    if (ok) ok = v != DAT_0033b4f0[11];
    if (ok) ok = v != DAT_0033b4f0[12];
    if (ok) ok = v != DAT_0033b4f0[13];
    if (ok) ok = v != DAT_0033b4f0[14];
    if (ok) ok = v != DAT_0033b4f0[15];
    if (ok) ok = v != DAT_0033b4f0[16];
    if (ok) ok = v != DAT_0033b4f0[17];
    if (!ok)
      return;
  }
  if (FUN_001c6cac(DAT_0034a114) != 0) {
    bool b = FUN_0012b760(self) != 0;
    if (!b)
      b = FUN_0012b7cc(self) != 0;
    if (b && it->f292 < 0) {
      int n = self->f836 - 1;
      self->f836 = n;
      if (n > 0)
        return;
      unsigned h = FUN_0001342c();
      h = h * 0x343fd + 0x269ec3;
      float f = (float)((h >> 16) & 0x7fff) * 3.0517578e-05f * 3.0f;
      f = ClampI(f, DAT_002da8f0, DAT_002da8f4);
      FUN_0012b470(self, (int)f, 1);
      FUN_001281e8(self);
      return;
    }
  }
  if (FUN_0012b7cc(self) != 0)
    FUN_0012b2b0(20.0f, self, 1, 1);
  FUN_001281e8(self);
}
