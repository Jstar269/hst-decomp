/* HSTMATCH module=EBOOT.BIN start=0x000df000 end=0x000df060 symbol=FUN_000df000 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: set found in the match branch, clear it after exhaustion, then select the byte before shared logical-not; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern char DAT_003417b8;
struct Self
{
  char pad[0x5e];
  unsigned char f5e;
  unsigned char f5f;
};

unsigned char FUN_000df000(struct Self *self)
{
  unsigned char c = self->f5e;
  if (c != 0) {
    int found;
    char *table = &DAT_003417b8;
    unsigned i = 0;
    for (; i < 2; i++) {
      if (table[i + 9] == '\t') {
        found = 1;
        goto decide;
      }
    }
    found = 0;
decide:
    unsigned char selected = found ? c : self->f5f;
    return !selected;
  }
  return c;
}
