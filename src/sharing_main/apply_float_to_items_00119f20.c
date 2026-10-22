/* HSTMATCH module=hstp_trans_main.prx start=0x00119f20 end=0x00119f8c symbol=FUN_00119f20 lang=c99 */
/* Clone of src/eboot/apply_float_to_items_0011110c.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Walks the pointer array at +0x04 of the object and writes the float parameter into element->f18 of
   every entry (FUN_00051d38 stores the float at +0x18 of the entry). The loop stops when the signed
   count at +0x08 is not positive.
   Matching idioms: `#pragma opt_strength_reduction off` keeps the index multiply (sll) inside the loop
   instead of walking a byte offset, the count and the array base are re-read from the object after every
   call (the callee may modify them), and the entry guard uses the plain member read (the count is
   re-loaded at the bottom of the loop). */
#pragma opt_strength_reduction off

typedef struct {
  int f0;
  void **f4;
  int f8;
} Obj;

extern void FUN_00051d38(void *p, float f);

void FUN_00119f20(Obj *self, float f)
{
  int i = 0;
  if (self->f8 > 0) {
    do {
      FUN_00051d38(self->f4[i], f);
      i++;
    } while (i < self->f8);
  }
}
