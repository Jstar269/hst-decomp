/* HSTMATCH module=EBOOT.BIN start=0x002535f0 end=0x00253628 symbol=FUN_002535f0 lang=c99 */
/* Hand-written reconstruction from the disassembly (index search over a member array); exact match verified; names and types await human review. */
struct S { char pad[0x38]; int count; int items[1]; };
int FUN_002535f0(struct S *self,int value)
{
  int i;
  int r;

  r = -1;
  for (i = 0; i < self->count; i++) {
    if (self->items[i] == value) {
      r = i;
      break;
    }
  }
  return r;
}
