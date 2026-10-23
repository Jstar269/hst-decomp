/* HSTMATCH module=EBOOT.BIN start=0x00117ff8 end=0x0011805c symbol=FUN_00117ff8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Grp { int count; char pad[0x6c]; };
struct Row { int ptrs[9]; };
struct Self {
  char pad[0x68];
  int f68;
  int f6c;
  int f70;
  char pad2[0xc0 - 0x74];
  struct Grp grps[1];
  char pad3[0x470 - 0x130];
  struct Row rows[1];
};

int FUN_00117ff8(struct Self *self, int a1)
{
  int slot;
  int r;

  slot = self->f70;
  r = 0;
  if (slot >= 0 && slot < self->grps[self->f68].count) {
    r = self->rows[a1].ptrs[self->f68] + slot * 0x60;
  }
  return r;
}
