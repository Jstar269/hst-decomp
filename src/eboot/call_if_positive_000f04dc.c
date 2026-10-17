/* HSTMATCH module=EBOOT.BIN start=0x000f04dc end=0x000f051c symbol=FUN_000f04dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v3) corrected by hand: the float test is written with the variable on the left (`x > 0.0f`, c.ngt.s) and the object is passed on to FUN_001031e8 (Ghidra dropped the argument); exact match verified; names and types await human review. */
typedef struct Obj_000f04dc {
  char pad0[0x54];
  unsigned char b54;
  char pad1[0x94 - 0x55];
  float f94;
} Obj_000f04dc;

extern void FUN_001031e8(Obj_000f04dc *);

void FUN_000f04dc(Obj_000f04dc *self)
{
  if (self->b54 == 0 && self->f94 > 0.0f) {
    FUN_001031e8(self);
  }
}
