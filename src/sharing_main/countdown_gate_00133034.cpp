/* HSTMATCH module=hstp_trans_main.prx start=0x00133034 end=0x001333a8 symbol=FUN_00133034 lang=c++ */
/* Clone of src/eboot/countdown_gate_00127dc4.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_003f344c;
extern int DAT_003e4830[18];
extern int DAT_00381970;
extern int DAT_00381974;
int FUN_001db984(int);
int FUN_001d50d4(int);
int FUN_00136bcc(Obj *);
int FUN_00136c38(Obj *);
unsigned FUN_0001342c();
void FUN_001368dc(Obj *, int, int);
void FUN_00133458(Obj *);
void FUN_0013671c(float, Obj *, int, int);
}

static inline float ClampI(float v, const int &lo, const int &hi)
{
  return v < (float)lo ? (float)lo : (!(v > (float)hi) ? v : (float)hi);
}

extern "C" void FUN_00133034(Obj *self)
{
  if (FUN_001db984(DAT_003f344c) == 0)
    return;
  Item *it = self->f58;
  if (it == 0)
    return;
  int v = it->f240;
  {
    int ok = v != DAT_003e4830[0];
    if (ok) ok = v != DAT_003e4830[1];
    if (ok) ok = v != DAT_003e4830[2];
    if (ok) ok = v != DAT_003e4830[3];
    if (ok) ok = v != DAT_003e4830[4];
    if (ok) ok = v != DAT_003e4830[5];
    if (ok) ok = v != DAT_003e4830[6];
    if (ok) ok = v != DAT_003e4830[7];
    if (ok) ok = v != DAT_003e4830[8];
    if (ok) ok = v != DAT_003e4830[9];
    if (ok) ok = v != DAT_003e4830[10];
    if (ok) ok = v != DAT_003e4830[11];
    if (ok) ok = v != DAT_003e4830[12];
    if (ok) ok = v != DAT_003e4830[13];
    if (ok) ok = v != DAT_003e4830[14];
    if (ok) ok = v != DAT_003e4830[15];
    if (ok) ok = v != DAT_003e4830[16];
    if (ok) ok = v != DAT_003e4830[17];
    if (!ok)
      return;
  }
  if (FUN_001d50d4(DAT_003f344c) != 0) {
    bool b = FUN_00136bcc(self) != 0;
    if (!b)
      b = FUN_00136c38(self) != 0;
    if (b && it->f292 < 0) {
      int n = self->f836 - 1;
      self->f836 = n;
      if (n > 0)
        return;
      unsigned h = FUN_0001342c();
      h = h * 0x343fd + 0x269ec3;
      float f = (float)((h >> 16) & 0x7fff) * 3.0517578e-05f * 3.0f;
      f = ClampI(f, DAT_00381970, DAT_00381974);
      FUN_001368dc(self, (int)f, 1);
      FUN_00133458(self);
      return;
    }
  }
  if (FUN_00136c38(self) != 0)
    FUN_0013671c(20.0f, self, 1, 1);
  FUN_00133458(self);
}
