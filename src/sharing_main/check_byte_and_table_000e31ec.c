/* HSTMATCH module=hstp_trans_main.prx start=0x000e31ec end=0x000e324c symbol=FUN_000e31ec lang=c99 */
/* Clone of src/eboot/check_byte_and_table_000df000.c (hstclone.py tag lnmc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: set found in the match branch, clear it after exhaustion, then select the byte before shared logical-not; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern char DAT_003eaaf0;
struct Self
{
  char pad[0x5e];
  unsigned char f5e;
  unsigned char f5f;
};

unsigned char FUN_000e31ec(struct Self *self)
{
  unsigned char c = self->f5e;
  if (c != 0) {
    int found;
    char *table = &DAT_003eaaf0;
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
