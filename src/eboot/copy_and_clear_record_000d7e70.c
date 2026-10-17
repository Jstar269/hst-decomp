/* HSTMATCH module=EBOOT.BIN start=0x000d7e70 end=0x000d7eb8 symbol=FUN_000d7e70 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: pointer arithmetic replaced by a struct with array members, signed short elements, rolled do-while loops with an unsigned counter (matching idiom: `do { } while (++i < N)` keeps the constant-trip loops rolled, a for loop is fully unrolled); exact match verified; names and types await human review. */
typedef struct Rec_000d7e70 {
  short h000[6];
  char pad00c[0x98];
  int w0a4[5];
  int w0b8;
  short h0bc[6];
} Rec_000d7e70;

void FUN_000d7e70(Rec_000d7e70 *o)
{
  unsigned int i = 0;
  do {
    o->h0bc[i] = o->h000[i];
  } while (++i < 6);
  o->w0b8 = -1;
  i = 0;
  do {
    o->w0a4[i] = 0;
  } while (++i < 5);
}
