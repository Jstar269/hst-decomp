/* HSTMATCH module=EBOOT.BIN start=0x000f0b24 end=0x000f0b64 symbol=FUN_000f0b24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v3) corrected by hand: the float test is written with the variable on the left (`x > 0.0f`, c.ngt.s) and the object is passed on to FUN_001031e8 (Ghidra dropped the argument); exact match verified; names and types await human review. */
typedef struct Obj_000f0b24 {
  char pad0[0x54];
  unsigned char b54;
  char pad1[0x80 - (0x54 + 1)];
  float f80;
} Obj_000f0b24;

extern void FUN_001031e8(Obj_000f0b24 *);

void FUN_000f0b24(Obj_000f0b24 *self)
{
  if (self->b54 == 0 && self->f80 > 0.0f) {
    FUN_001031e8(self);
  }
}
