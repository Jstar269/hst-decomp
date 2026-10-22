/* HSTMATCH module=hstp_trans_main.prx start=0x00185834 end=0x00185884 symbol=FUN_00185834 lang=c99 */
/* Clone of src/eboot/find_ptr_index_001791a8.c (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Searches the pointer array at +0x01e4 (each element points to the int that is compared) for the value
   param_2 and returns its index, or 0x7fffffff when the array is empty / the value is not in it.
   Sibling of find_ptr_index_b_00179210.c and find_ptr_index_c_00179260.c (the same code at +0x01fc/+0x0208).
   Matching idioms: #pragma opt_strength_reduction off keeps retail's per-iteration "sll idx,2" instead of
   a byte offset; the guard and the loop bound read the count in DIFFERENT FORMS (a direct member access
   for one, a raw pointer read for the other) - with the same form twice the compiler CSEs the two loads
   and keeps the count in a register instead of re-reading it in the branch delay slot; the index is
   compared with the parameter first ("param_2 == *arr[i]" gives retail's "bnel a1,v1"). */
#pragma opt_strength_reduction off

typedef struct {
  char pad01e4[0x01e4];
  int **arr;
  unsigned count;
} Self;

unsigned FUN_00185834(Self *self, int param_2)
{
  unsigned i = 0;
  if (self->count != 0) {
    do {
      if (param_2 == *self->arr[i]) {
        return i;
      }
      i++;
    } while (i < *(unsigned *)((char *)self + 0x01e8));
  }
  return 0x7fffffff;
}
