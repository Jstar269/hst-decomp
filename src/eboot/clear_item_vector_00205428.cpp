/* HSTMATCH module=EBOOT.BIN start=0x00205428 end=0x002054b0 symbol=FUN_00205428 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed struct with the item vector, delete-style FUN_00055e48(p, 1) loop with offset pointer, size cleared via shrink(n, Alloc()); exact match verified; names and types await human review. */

struct Alloc {};
struct Vec { int **data; unsigned size; void shrink(int n, Alloc) { size -= n; } };

struct Self {
  char pad[0xc];
  int **items;
  unsigned count;
};

extern "C" int FUN_00055e48(int *, int);

extern "C" void FUN_00205428(Self *self)
{
  unsigned j = 0;
  if (self->count != 0) {
    int i = 0;
    do {
      int *p = *(int **)((char *)self->items + i);
      if (p != 0) {
        FUN_00055e48(p, 1);
        *(int **)((char *)self->items + i) = 0;
      }
      j++;
      i += 4;
    } while (j < self->count);
  }
  int n = ((Vec *)&self->items)->size;
  ((Vec *)&self->items)->shrink(n, Alloc());
}
