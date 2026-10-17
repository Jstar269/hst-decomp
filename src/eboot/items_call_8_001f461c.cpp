/* HSTMATCH module=EBOOT.BIN start=0x001f461c end=0x001f46b4 symbol=FUN_001f461c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item {
  char pad[0x58];
  int f58;
};

struct Obj {
  char pad[0x3a0];
  Item *items[4];
  int args[4];
};

extern "C" void FUN_001f37e4(Obj *, Item *, int, int, int, int);

extern "C" void FUN_001f461c(Obj *self, Item *which)
{
  for (int i = 0; i < 4; i++) {
    if (which == 0 || which == self->items[i]) {
      Item *it = self->items[i];
      int f = it ? it->f58 : 0;
      if (f != 0) {
        FUN_001f37e4(self, it, self->args[i], i, 8, 0);
      }
    }
  }
}
