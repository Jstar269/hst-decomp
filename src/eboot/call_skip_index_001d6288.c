/* HSTMATCH module=EBOOT.BIN start=0x001d6288 end=0x001d62f8 symbol=FUN_001d6288 lang=c99 */
/* Hand-written reconstruction from the disassembly (rolled i*4 dispatch loop kept by pragmas); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off

/* Object holding an array of item pointers and their count. */
typedef struct ItemArray { char pad00[0x10]; void **items; int count; } ItemArray;

extern void FUN_000ffb3c();

/* Call FUN_000ffb3c on every item with a flag that is 0 only for the item at index skip. */
void FUN_001d6288(ItemArray *self,int skip)
{
  for (int i = 0; i < self->count; i++) {
    FUN_000ffb3c(self->items[i], i != skip);
  }
}
