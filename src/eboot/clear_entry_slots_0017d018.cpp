/* HSTMATCH module=EBOOT.BIN start=0x0017d018 end=0x0017d1f0 symbol=FUN_0017d018 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed structs, loop index/idx declaration order, unk54-flag block as store-then-test (unk54 = 1; if (unk54 != 0) { unk50 = 1; unk54 = 0; }) in an if (unk50 != 1) / else, vector clear as shrink(n, Alloc()) through a Vec cast; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_mgr.h"

struct Alloc {};
struct Vec { int **data; unsigned size; void shrink(int n, Alloc) { size -= n; } };

extern "C" int FUN_00055e48(int *, int);
extern "C" void FUN_00092c38(void *, int);
extern "C" void FUN_000943d0(void *, int);
extern "C" int FUN_00204290(int);

/* Clear the entry's marked sub-values and, if any value is set, reset its state and free the item list. */
extern "C" void FUN_0017d018(SlotMgr *self, int idx, int *vals, int flagA, int flagB)
{
  SlotEntry *e = self->entries[idx];
  int i = 0;
  do {
    int k = FUN_00204290(i);
    if (vals[k] != VALUE_UNSET) {
      FUN_00092c38(e->sub, k);
      if (k == 5) FUN_000943d0(e->sub, 5);
      else if (k == 3) FUN_000943d0(e->sub, 3);
      else if (k == 4) FUN_000943d0(e->sub, 4);
    }
    i++;
  } while (i < 6);
  if (vals[0] != VALUE_UNSET || vals[2] != VALUE_UNSET || vals[1] != VALUE_UNSET) {
    if (flagB != 0) {
      if (idx == self->cur) {
        if (self->unk50 != 1) {
          self->unk54 = 1;
          if (self->unk54 != 0) { self->unk50 = 1; self->unk54 = 0; }
        } else {
          if (self->unk54 != 0) self->unk54 = 0;
        }
      }
      e->unk4 = 0;
    }
    if (flagA != 0) {
      unsigned j = 0;
      if (self->count != 0) {
        do {
          int *p = self->items[j];
          if (p != 0) {
            FUN_00055e48(p, 1);
            self->items[j] = 0;
          }
          j++;
        } while (j < self->count);
      }
      int n = ((Vec *)&self->items)->size;
      ((Vec *)&self->items)->shrink(n, Alloc());
    }
  }
}
