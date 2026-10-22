/* HSTMATCH module=EBOOT.BIN start=0x0005ef18 end=0x0005eff8 symbol=FUN_0005ef18 lang=c++ */
struct Obj {
  char pad[0xa0];
  unsigned f_a0;
  char pad2[4];
  int *f_a8;
  unsigned f_ac;
  char pad3[4];
  unsigned *f_b4;
};

extern "C" void FUN_0005f030(float f, void *obj, int flag);
extern "C" void FUN_0005d818();

extern "C" void FUN_0005ef18(Obj *self)
{
  unsigned i = 0;
  if (self->f_ac != 0) {
    do {
      if ((int)i >= 0 && i < self->f_ac) {
        if (self->f_a0 == i) {
          FUN_0005f030(0.0f, self, -1);
        }
        int v = self->f_a8[i];
        if (v != 0) {
          if ((self->f_b4[i >> 5] & (1 << (i & 0x1f))) == 0) {
            self->f_a8[i] = 0;
          } else if (v != 0) {
            FUN_0005d818();
            self->f_a8[i] = 0;
          }
        }
      }
      i++;
    } while (i < self->f_ac);
  }
}
// NEAR MISS: 112/112 words, 50 differ.
// The control flow is right (the do-while with the re-read f_ac bound, the f_a0 compare and the
// bitmask test) but retail keeps only TWO saved registers (s1 = self, s0 = the counter) and
// recomputes the array index (sll a0,s0,0x2) on every access, while ours grows a third saved
// register: the byte offset (s0 += 4) as a strength-reduced induction variable plus the counter
// in s1 (so self lands in s2).
// Ruled out: #pragma opt_strength_reduction off (before the header and after it), an inline
// operator[] on a wrapper struct for the pointer and the bitmask arrays, a char* base with
// base + i*4, a signed counter with (unsigned) casts, and the store before the bitmask test.
// near miss from lane om1 (unreviewed)
