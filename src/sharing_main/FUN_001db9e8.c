/* HSTMATCH module=hstp_trans_main.prx start=0x001db9e8 end=0x001dba30 symbol=FUN_001db9e8 lang=c99 */
/* Clone of src/eboot/FUN_001cd30c.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad0[0x4c];
  void **items;
  unsigned count;
  char pad1[0x94];
  int idx;
} Self;

void *FUN_001db9e8(Self *self)
{
  void *p;
  void *r;

  if (0 <= self->idx && self->idx < self->count && (p = self->items[self->idx]) != 0)
    r = p;
  else
    r = 0;
  return r;
}
