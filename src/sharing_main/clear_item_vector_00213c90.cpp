/* HSTMATCH module=hstp_trans_main.prx start=0x00213c90 end=0x00213d18 symbol=FUN_00213c90 lang=c++ */
/* Clone of src/eboot/clear_item_vector_00205428.cpp (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed struct with the item vector, delete-style FUN_000569f4(p, 1) loop with offset pointer, size cleared via shrink(n, Alloc()); exact match verified; names and types await human review. */

struct Alloc {};
struct Vec { int **data; unsigned size; void shrink(int n, Alloc) { size -= n; } };

struct Self {
  char pad[0xc];
  int **items;
  unsigned count;
};

extern "C" int FUN_000569f4(int *, int);

extern "C" void FUN_00213c90(Self *self)
{
  unsigned j = 0;
  if (self->count != 0) {
    int i = 0;
    do {
      int *p = *(int **)((char *)self->items + i);
      if (p != 0) {
        FUN_000569f4(p, 1);
        *(int **)((char *)self->items + i) = 0;
      }
      j++;
      i += 4;
    } while (j < self->count);
  }
  int n = ((Vec *)&self->items)->size;
  ((Vec *)&self->items)->shrink(n, Alloc());
}
