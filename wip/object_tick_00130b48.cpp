/* HSTMATCH module=EBOOT.BIN start=0x00130b48 end=0x00130cf8 symbol=FUN_00130b48 lang=c++ */
/* Hand-written reconstruction from the disassembly; near miss, not exact; names and types await human review. */
struct Sub80 {
  char pad[0x58];
  int f58;
};
struct Obj {
  char pad0[0x3c];
  int f3c;
  int f40;
  char pad1[4];
  int f48;
  unsigned char f4c;
  char pad2[0x33];
  Sub80 *f80;
  char pad3[8];
  int f8c;
  char pad4[0x90];
  int f120;
  char pad5[0x10];
  unsigned char f134;
};
struct GameA { char pad[0x3c]; int f3c; };
struct GameB { char pad[0x3c]; int f3c; int f40; };
extern GameA *DAT_003386b0;
extern GameB *DAT_00340284;
extern char DAT_0033b5d5;
extern char DAT_0033b5d6;
extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_00063dc8(float, void *);
extern "C" void FUN_00063eb4(float, void *);
extern "C" void FUN_00063e44(void *, int);
struct Item { int f0; float f4; };

extern "C" void FUN_00130b48(Obj *o)
{
  if (o->f120 >= 0) {
    o->f120 = o->f120 + 1;
  }
  if (o->f8c == 1 && o->f80 != 0) {
    int off = o->f80->f58 * 0x58;
    if ((&DAT_0033b5d5)[off] == 1 || (&DAT_0033b5d6)[off] == 1 || (&DAT_0033b5d5)[off] == 2 || (&DAT_0033b5d6)[off] == 2) {
      o->f134 = 1;
    }
  }
  if (DAT_003386b0->f3c == 7) {
    if (o->f48 == 0) {
      int ok = 1;
      if (o->f40 >= 0 && o->f3c < o->f40) {
        ok = 0;
      }
      if (!ok) {
        void *p = FUN_00000bcc(0x20);
        if (p) p = FUN_00063dc8(-1.0f, p);
        o->f48 = (int)p;
        FUN_00063eb4(3000.0f, p);
        ((Item *)o->f48)->f4 = 3000.0f;
        o->f4c = 1;
      }
    }
  }
  if (o->f40 >= 0) {
    o->f3c = o->f3c + 1;
  }
  int q = o->f48;
  if (q != 0) {
    int b = DAT_00340284->f40 < 0;
    if (!b) b = DAT_00340284->f40 <= DAT_00340284->f3c;
    if (b && q != 0) {
      FUN_00063e44((void *)q, 1);
      o->f48 = 0;
    }
  }
}
// Near miss (8 words): only the register colours of the final block differ. Retail: `lui v1; lw a2,644(v1); lw a1,64(a2); slt v1,a1,zero; bnez v1,L; lw v1,60(a2); slt v1,v1,a1; xori v1,v1,1; L: beqz v1,...`
// (pointer in a2, flag in v1); ours puts the pointer in v1 and the flag in a2 (lui temp coalesced with the loaded pointer).
// Ruled out (all give the same 8 words or worse): local `GameB *g = DAT_00340284;`, `int n = f40;` local, `bool`/`unsigned char` flag,
// flag declared at function top / shared with the earlier `ok`, inline `Past(GameB*)` helper (flag-var, early-return, `||` forms),
// `char *`/`int` typed global with casts, `b = f40 < 0 || f40 <= f3c`, `if (b) { if (q) ..}` nesting, `b != 0 && q != 0`.
// Everything before 0x130cac is exact (struct layout, the 0x58-stride table lookups with two separate lui/addiu bases, the alloc/ctor/f48 chain).
