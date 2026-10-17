/* HSTMATCH module=EBOOT.BIN start=0x0017bc60 end=0x0017bce8 symbol=FUN_0017bc60 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed struct with the item vector, delete-style FUN_00055e48(p, 1) loop with the index first, size cleared as int n = size; shrink(n, Alloc()) (as in 0x17d018); exact match verified; names and types await human review. */
struct Alloc {};
struct Vec { int **data; unsigned size; void shrink(int n, Alloc) { size -= n; } };
struct Self {
  char pad[0x14];
  int **items;
  unsigned count;
};
extern "C" int FUN_00055e48(int *, int);

extern "C" void FUN_0017bc60(Self *self)
{
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
