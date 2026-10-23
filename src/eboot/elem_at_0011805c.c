/* HSTMATCH module=EBOOT.BIN start=0x0011805c end=0x001180b0 symbol=FUN_0011805c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Row {
  int count;                  /* 0x00 */
  unsigned char pad04[0x6c];
};

struct Self {
  unsigned char pad00[0x68];
  int index;                  /* 0x68 */
  unsigned char pad6c[4];
  int i;                      /* 0x70 */
  unsigned char pad74[0x4c];
  struct Row rows[1];         /* 0xc0 */
  unsigned char pad130[0x3d0];
  int table[1];               /* 0x500 */
};

int FUN_0011805c(struct Self *self)
{
  int i;
  int r;

  i = self->i;
  r = 0;
  if ((i >= 0) && (i < self->rows[self->index].count)) {
    r = self->table[self->index] + i * 0x30;
  }
  return r;
}
