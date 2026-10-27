/* HSTMATCH module=hstp_trans_main.prx start=0x0020c948 end=0x0020c9c4 symbol=__ct__10C_0020c948Fv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of a 0x144-byte table (embedded twice in the object built by 0x00187ab0): ten 32-byte entries
   {int = 0x7fffffff, four zero bytes, six ints = 0x7fffffff} built by the compiler's array-ctor loop
   (`do { ctor(p); p += 32; } while (p < end)`), then count = 0 and FUN_0020c9c4 (src/sharing_main/FUN_0020c9c4.c),
   which re-initialises the ten entries the same way. Retail keeps that loop rolled: matching idiom
   `#pragma opt_unroll_loops off` (without it MWCC peels and unrolls it 8x, 162 words). Twin of EBOOT 0x001fe178. */
#pragma opt_unroll_loops off

struct C_0020c948;
extern "C" void FUN_0020c9c4(C_0020c948 *self);

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

struct C_0020c948 {
  Entry entries[10];
  int count;
  C_0020c948();
};

C_0020c948::C_0020c948()
{
  count = 0;
  FUN_0020c9c4(this);
}
