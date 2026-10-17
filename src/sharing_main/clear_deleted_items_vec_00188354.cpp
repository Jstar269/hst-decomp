/* HSTMATCH module=hstp_trans_main.prx start=0x00188354 end=0x001883dc symbol=FUN_00188354 lang=c++ */
/* Clone of src/eboot/clear_deleted_items_vec_0017bc60.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed struct with the item vector, delete-style FUN_000569f4(p, 1) loop with the index first, size cleared as int n = size; shrink(n, Alloc()) (as in 0x17d018); exact match verified; names and types await human review. */
struct Alloc {};
struct Vec { int **data; unsigned size; void shrink(int n, Alloc) { size -= n; } };
struct Self {
  char pad[0x14];
  int **items;
  unsigned count;
};
extern "C" int FUN_000569f4(int *, int);

extern "C" void FUN_00188354(Self *self)
{
  unsigned j = 0;
  if (self->count != 0) {
    do {
      int *p = self->items[j];
      if (p != 0) {
        FUN_000569f4(p, 1);
        self->items[j] = 0;
      }
      j++;
    } while (j < self->count);
  }
  int n = ((Vec *)&self->items)->size;
  ((Vec *)&self->items)->shrink(n, Alloc());
}
