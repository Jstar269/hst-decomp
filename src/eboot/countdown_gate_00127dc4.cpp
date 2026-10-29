/* HSTMATCH module=EBOOT.BIN start=0x00127dc4 end=0x00128138 symbol=FUN_00127dc4 lang=c++ */
/* Hand-written reconstruction from the disassembly (Ghidra tag a1 pseudocode as the guide); exact match verified (matching idioms: the 18-way inequality chain is a materialised flag 'ok = v != G0; if (ok) ok = v != G1; ...', the pseudo-random draw is '(h >> 16) & 0x7fff' on an unsigned so MWCC emits ext, and the clamp between two int globals is an inline ClampI(float, const int&, const int&) with 'v < lo ? lo : (!(v > hi) ? v : hi)'); names and types await human review. */
#include "hst/motion_obj.h"

extern "C" {
extern int DAT_0034a114;
extern int DAT_0033b4f0[ID_TABLE_COUNT];
extern int DAT_002da8f0;
extern int DAT_002da8f4;
int FUN_001cd2a8(int);
int FUN_001c6cac(int);
int FUN_0012b760(MotionObj *);
int FUN_0012b7cc(MotionObj *);
unsigned FUN_0001342c();
void FUN_0012b470(MotionObj *, int, int);
void FUN_001281e8(MotionObj *);
void FUN_0012b2b0(float, MotionObj *, int, int);
}

static inline float ClampI(float value, const int &lo, const int &hi)
{
  return value < (float)lo ? (float)lo : (!(value > (float)hi) ? value : (float)hi);
}

/* Does nothing while the linked item's id is in the id table; otherwise counts down and, at zero, draws a random delay. */
extern "C" void FUN_00127dc4(MotionObj *self)
{
  if (FUN_001cd2a8(DAT_0034a114) == 0)
    return;
  MotionItem *item = self->item;
  if (item == 0)
    return;
  int id = item->unkf0;
  {
    int unlisted = id != DAT_0033b4f0[0];
    if (unlisted) unlisted = id != DAT_0033b4f0[1];
    if (unlisted) unlisted = id != DAT_0033b4f0[2];
    if (unlisted) unlisted = id != DAT_0033b4f0[3];
    if (unlisted) unlisted = id != DAT_0033b4f0[4];
    if (unlisted) unlisted = id != DAT_0033b4f0[5];
    if (unlisted) unlisted = id != DAT_0033b4f0[6];
    if (unlisted) unlisted = id != DAT_0033b4f0[7];
    if (unlisted) unlisted = id != DAT_0033b4f0[8];
    if (unlisted) unlisted = id != DAT_0033b4f0[9];
    if (unlisted) unlisted = id != DAT_0033b4f0[10];
    if (unlisted) unlisted = id != DAT_0033b4f0[11];
    if (unlisted) unlisted = id != DAT_0033b4f0[12];
    if (unlisted) unlisted = id != DAT_0033b4f0[13];
    if (unlisted) unlisted = id != DAT_0033b4f0[14];
    if (unlisted) unlisted = id != DAT_0033b4f0[15];
    if (unlisted) unlisted = id != DAT_0033b4f0[16];
    if (unlisted) unlisted = id != DAT_0033b4f0[17];
    if (!unlisted)
      return;
  }
  if (FUN_001c6cac(DAT_0034a114) != 0) {
    bool ready = FUN_0012b760(self) != 0;
    if (!ready)
      ready = FUN_0012b7cc(self) != 0;
    if (ready && item->unk124 < 0) {
      int left = self->countdown - 1;
      self->countdown = left;
      if (left > 0)
        return;
      unsigned seed = FUN_0001342c();
      seed = seed * 0x343fd + 0x269ec3;  /* linear congruential step */
      float delay = (float)((seed >> 16) & 0x7fff) * 3.0517578e-05f * 3.0f;
      delay = ClampI(delay, DAT_002da8f0, DAT_002da8f4);
      FUN_0012b470(self, (int)delay, 1);
      FUN_001281e8(self);
      return;
    }
  }
  if (FUN_0012b7cc(self) != 0)
    FUN_0012b2b0(20.0f, self, 1, 1);
  FUN_001281e8(self);
}
