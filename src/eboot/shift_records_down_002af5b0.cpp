/* HSTMATCH module=EBOOT.BIN start=0x002af5b0 end=0x002af6ec symbol=FUN_002af5b0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct F2 { float x, y; };

struct Rec {
  char f0[16];
  F2 v;
  char f18[21];
  float f30;
  int f34;
  int f38;
  char f3c[75];
  int f88;
  int f8c;
  int f90;
  int f94;
  int f98;
  int f9c;
  float fa0;
  float fa4;
  int fa8;
  int fac;
  Rec() {}
};

extern "C" void FUN_002af5b0(int param_1, int param_2)
{
  Rec *src;
  Rec *dst = (Rec *)(param_1 + param_2 * 0xb0);
  Rec *end = (Rec *)(param_1 + 0x44c0);

  for (src = dst + 1; src < end; ++src, ++dst) {
    *dst = *src;
  }
}
