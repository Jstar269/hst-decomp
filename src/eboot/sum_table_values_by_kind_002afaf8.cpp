/* HSTMATCH module=EBOOT.BIN start=0x002afaf8 end=0x002afb80 symbol=FUN_002afaf8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sums the float values of the 30 eight-byte table records (DAT_0034b5d4) with index <= n into out[kind], kind being
   the record's low 4-bit signed field (the upper 28 bits are the value FUN_002afa48 compares, read as `word >> 4`).
   The record lookup is a bounds-checked member getter of the table object (its `this` is loaded before the range
   test, which puts retail's global load in the bltz delay slot); `n >= i` keeps the slt result in a GPR (bnezl).
   Names provisional. */
struct Rec {
  int kind : 4;
  int pos : 28;
  float value;
};

struct Table {
  Rec rec[30];
  Rec *Get(int i) {
    if (0 <= i && i < 30) return &rec[i];
    return 0;
  }
};

extern "C" Table *DAT_0034b5d4;

extern "C" void FUN_002afaf8(float *out, int n)
{
  for (int k = 0; k < 5; k++) out[k] = 0.0f;
  for (int i = 0; i < 30; i++) {
    if (n >= i) {
      Rec *r = DAT_0034b5d4->Get(i);
      out[r->kind] += r->value;
    }
  }
}
