/* HSTMATCH module=EBOOT.BIN start=0x00053e08 end=0x00053e90 symbol=FUN_00053e08 lang=c++ */
/* Clone of src/sharing_main/release_items_00054954.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: opt_strength_reduction off (retail recomputes index*4 per pass); the loop reads items/count as plain fields while the two clears read size through a Vec view, so the size is reloaded after the loop (no CSE with the loop test). */
#pragma opt_strength_reduction off
struct Alloc {};
struct Vec { int *data; unsigned size; void shrink(int n, Alloc) { size -= n; } };

struct Self {
  char pad[0x14];
  unsigned char active;
  char pad15[3];
  int *items;
  unsigned count;
  char pad20[0x24 - 0x20];
  int *other;
  unsigned other_count;
};

extern "C" void FUN_0004fe04(void *, int);
extern char DAT_00311170[];

extern "C" void FUN_00053e08(Self *self)
{
  if (self->active != 0) {
    int i = 0;
    if (self->count != 0) {
      do {
        FUN_0004fe04(DAT_00311170, self->items[i]);
        i++;
      } while (i < self->count);
    }
    {
      int n = ((Vec *)&self->items)->size;
      ((Vec *)&self->items)->shrink(n, Alloc());
    }
    {
      int n = ((Vec *)&self->other)->size;
      ((Vec *)&self->other)->shrink(n, Alloc());
    }
    self->active = 0;
  }
}
