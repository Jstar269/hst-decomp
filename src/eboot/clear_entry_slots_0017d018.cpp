/* HSTMATCH module=EBOOT.BIN start=0x0017d018 end=0x0017d1f0 symbol=FUN_0017d018 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed structs, loop index/idx declaration order, f54-flag block as store-then-test (f54 = 1; if (f54 != 0) { f50 = 1; f54 = 0; }) in an if (f50 != 1) / else, vector clear as shrink(n, Alloc()) through a Vec cast; exact match verified; names and types await human review. */
struct Alloc {};
struct Vec { int **data; unsigned size; void shrink(int n, Alloc) { size -= n; } };
struct Slot { int pad[4]; };
struct Entry { int pad[1]; int f4; int pad2[2]; char sub[1]; };
struct Self {
  int pad0;
  int cur;
  Entry **entries;
  char pad1[0x14 - 0xc];
  int **items;
  unsigned count;
  char pad2[0x50 - 0x1c];
  int f50;
  int f54;
};
extern "C" int FUN_00055e48(int *, int);
extern "C" void FUN_00092c38(void *, int);
extern "C" void FUN_000943d0(void *, int);
extern "C" int FUN_00204290(int);

extern "C" void FUN_0017d018(Self *self, int idx, int *vals, int flagA, int flagB)
{
  Entry *e = self->entries[idx];
  int i = 0;
  do {
    int k = FUN_00204290(i);
    if (vals[k] != 0x7fffffff) {
      FUN_00092c38(&e->sub, k);
      if (k == 5) FUN_000943d0(&e->sub, 5);
      else if (k == 3) FUN_000943d0(&e->sub, 3);
      else if (k == 4) FUN_000943d0(&e->sub, 4);
    }
    i++;
  } while (i < 6);
  if (vals[0] != 0x7fffffff || vals[2] != 0x7fffffff || vals[1] != 0x7fffffff) {
    if (flagB != 0) {
      if (idx == self->cur) {
        if (self->f50 != 1) {
          self->f54 = 1;
          if (self->f54 != 0) { self->f50 = 1; self->f54 = 0; }
        } else {
          if (self->f54 != 0) self->f54 = 0;
        }
      }
      e->f4 = 0;
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
