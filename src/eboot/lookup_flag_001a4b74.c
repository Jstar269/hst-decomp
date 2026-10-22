/* HSTMATCH module=EBOOT.BIN start=0x001a4b74 end=0x001a4bc8 symbol=FUN_001a4b74 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Looks param_2 up in the int table at +0x360 (length +0x364) and returns whether the parallel table at
   +0x36c holds a non-zero entry for the same index; 0 when the value is not in the table.
   Matching idioms: #pragma opt_strength_reduction off keeps retail's per-iteration "sll idx,2"; the guard
   and the loop bound read the length in DIFFERENT FORMS (direct member vs raw pointer read) so that the
   compiler re-reads it in the branch delay slot instead of keeping it in a register; the boolean is
   materialised as retail's "sltu v0,zero,v0". */
#pragma opt_strength_reduction off

typedef struct {
  char pad360[0x360];
  int *arr;
  unsigned count;
  char pad368[0x36c - 0x368];
  int *other;
} Self;

int FUN_001a4b74(Self *self, int param_2)
{
  unsigned i = 0;
  if (self->count != 0) {
    do {
      if (param_2 == self->arr[i]) {
        return self->other[i] != 0;
      }
      i++;
    } while (i < *(unsigned *)((char *)self + 0x364));
  }
  return 0;
}
