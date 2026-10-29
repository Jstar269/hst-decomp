/* HSTMATCH module=EBOOT.BIN start=0x00294554 end=0x00294564 symbol=FUN_00294554 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct Sized {
  int unk0;   /* 0x00 */
  int size;   /* 0x04 */
} Sized;

/* Shrinks the element count by n. */
void FUN_00294554(Sized *self,int n)
{
  self->size = self->size - n;
}
