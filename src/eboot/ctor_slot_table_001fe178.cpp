/* HSTMATCH module=EBOOT.BIN start=0x001fe178 end=0x001fe1f4 symbol=__ct__10C_001fe178Fv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of a 0x144-byte table (embedded twice in the object built by 0x0017b3bc): ten 32-byte entries
   {int = 0x7fffffff, four zero bytes, six ints = 0x7fffffff} built by the compiler's array-ctor loop
   (`do { ctor(p); p += 32; } while (p < end)`), then count = 0 and FUN_001fe1f4 (src/eboot/FUN_001fe1f4.c),
   which re-initialises the ten entries the same way. Retail keeps that loop rolled: matching idiom
   `#pragma opt_unroll_loops off` (without it MWCC peels and unrolls it 8x, 162 words). Twin of hstp_trans_main.prx 0x0020c948. */
#pragma opt_unroll_loops off

struct C_001fe178;
extern "C" void FUN_001fe1f4(C_001fe178 *self);

struct Entry {
  int key;
  unsigned char flags[4];
  int vals[6];
  Entry()
  {
    key = 0x7fffffff;
    flags[0] = 0;
    flags[1] = 0;
    flags[2] = 0;
    flags[3] = 0;
    vals[0] = 0x7fffffff;
    vals[1] = 0x7fffffff;
    vals[2] = 0x7fffffff;
    vals[3] = 0x7fffffff;
    vals[4] = 0x7fffffff;
    vals[5] = 0x7fffffff;
  }
};

struct C_001fe178 {
  Entry entries[10];
  int count;
  C_001fe178();
};

C_001fe178::C_001fe178()
{
  count = 0;
  FUN_001fe1f4(this);
}
