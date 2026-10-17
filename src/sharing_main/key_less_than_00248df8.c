/* HSTMATCH module=hstp_trans_main.prx start=0x00248df8 end=0x00248e90 symbol=FUN_00248df8 lang=c99 */
/* Clone of src/eboot/key_less_than_00238cc0.c (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Key {
  unsigned short s[6];
  unsigned int w;
};

int FUN_00248df8(struct Key *a, struct Key *b)
{
  if (a->s[0] != b->s[0]) return a->s[0] < b->s[0];
  if (a->s[1] != b->s[1]) return a->s[1] < b->s[1];
  if (a->s[2] != b->s[2]) return a->s[2] < b->s[2];
  if (a->s[3] != b->s[3]) return a->s[2] < b->s[3];
  if (a->s[4] != b->s[4]) return a->s[4] < b->s[4];
  if (a->s[5] != b->s[5]) return a->s[5] < b->s[5];
  if (a->w != b->w) return a->w < b->w;
  return 0;
}

// Note: retail's 4th stage compares s[2] (kept live in a2 from the 3rd stage) against b->s[3]; reproduced as written above.
