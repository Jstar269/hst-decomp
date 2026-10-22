/* HSTMATCH module=EBOOT.BIN start=0x0005f030 end=0x0005f0d8 symbol=FUN_0005f030 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Selects a new entry in a table held by the object: the new index is stored at +0xa0,
   the old table entry at +0xa4 is released with FUN_0005d98c(entry, -1.0f), the entry
   for the new index is looked up in the array at +0xa8 (count at +0xac) and stored at
   +0xa4, and the object is refreshed (FUN_0005f110) when an entry was found.
   The float parameter (f12) is the value handed to FUN_0005f110. */
struct Self {
  char pad[0xa0];
  int f_a0;
  int f_a4;
  int *f_a8;
  unsigned int f_ac;
  char pad2[0x18];
  float f_c8;
};

extern void FUN_0005d98c(int a, float b);
extern void FUN_0005f110(struct Self *self, float f);

void FUN_0005f030(float f, struct Self *self, int value)
{
  if (self->f_a0 != value) {
    self->f_a0 = value;
    if (self->f_a4 != 0) {
      FUN_0005d98c(self->f_a4, -1.0f);
    }
    int idx = self->f_a0;
    if (idx >= 0 && (unsigned int)idx < self->f_ac) {
      self->f_a4 = self->f_a8[idx];
    } else {
      self->f_a4 = 0;
    }
    if (self->f_a4 != 0) {
      self->f_c8 = -1.0f;
      FUN_0005f110(self, f);
    }
  }
}
