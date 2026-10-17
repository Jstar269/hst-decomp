/* HSTMATCH module=hstp_trans_main.prx start=0x0009e534 end=0x0009e5f0 symbol=FUN_0009e534 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idioms: the four-step chain is materialised int flags (declared c, b, a so that a gets a1, b a2, c a3); the negated tests are `(x == 7) ^ 1` and `(flag != 0) ^ 1` (retail xori 1 after sltiu/sltu), a plain `!=`/`==` folds into a branch instead.
typedef struct { char pad[0x3c]; int f3c; char pad1[0x88 - 0x40]; struct { char pad[0x22c]; int f22c; } *f88; } A;
typedef struct { char pad[0x5d]; unsigned char f5d; unsigned char f5e; char pad1[0x9c - 0x5f]; int f9c; } B;
extern A *DAT_003e19f0;
extern B *DAT_003e1e84;

int FUN_0009e534(void)
{
  int r = 0;
  int c = 0;
  int b = 0;
  int a = 0;
  A *g = DAT_003e19f0;
  if (((g->f3c == 7) ^ 1) && g->f88->f22c == 4) a = 1;
  if (a && DAT_003e1e84->f9c < 0) b = 1;
  if (b && ((DAT_003e1e84->f5d != 0) ^ 1)) c = 1;
  if (c && ((DAT_003e1e84->f5e != 0) ^ 1)) r = 1;
  return r;
}
