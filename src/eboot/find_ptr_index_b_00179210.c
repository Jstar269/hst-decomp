/* HSTMATCH module=EBOOT.BIN start=0x00179210 end=0x00179260 symbol=FUN_00179210 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Searches the pointer array at +0x01fc (each element points to the int that is compared) for the value
   param_2 and returns its index, or 0x7fffffff when the array is empty / the value is not in it.
   Sibling of find_ptr_index_001791a8.c (the same code with the array at +0x1e4).
   Matching idioms: #pragma opt_strength_reduction off keeps retail's per-iteration "sll idx,2" instead of
   a byte offset; the guard and the loop bound read the count in DIFFERENT FORMS (a direct member access
   for one, a raw pointer read for the other) - with the same form twice the compiler CSEs the two loads
   and keeps the count in a register instead of re-reading it in the branch delay slot; the index is
   compared with the parameter first ("param_2 == *arr[i]" gives retail's "bnel a1,v1"). */
#pragma opt_strength_reduction off

typedef struct {
  char pad01fc[0x01fc];
  int **arr;
  unsigned count;
} Self;

unsigned FUN_00179210(Self *self, int param_2)
{
  unsigned i = 0;
  if (self->count != 0) {
    do {
      if (param_2 == *self->arr[i]) {
        return i;
      }
      i++;
    } while (i < *(unsigned *)((char *)self + 0x0200));
  }
  return 0x7fffffff;
}
