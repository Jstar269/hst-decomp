/* HSTMATCH module=EBOOT.BIN start=0x000f23d0 end=0x000f2410 symbol=FUN_000f23d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v3) corrected by hand: the float test is written with the variable on the left (`x > 0.0f`, c.ngt.s) and the object is passed on to FUN_001031e8 (Ghidra dropped the argument); exact match verified; names and types await human review. */
typedef struct Obj_000f23d0 {
  char pad0[0x74];
  float f74;
  char pad1[0x84 - 0x78];
  unsigned char b84;
} Obj_000f23d0;

extern void FUN_001031e8(Obj_000f23d0 *);

void FUN_000f23d0(Obj_000f23d0 *self)
{
  if (self->b84 != 0 && self->f74 > 0.0f) {
    FUN_001031e8(self);
  }
}
