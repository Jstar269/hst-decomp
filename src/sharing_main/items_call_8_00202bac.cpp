/* HSTMATCH module=hstp_trans_main.prx start=0x00202bac end=0x00202c44 symbol=FUN_00202bac lang=c++ */
/* Clone of src/eboot/items_call_8_001f461c.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_00201ca4(Obj *, Item *, int, int, int, int);

extern "C" void FUN_00202bac(Obj *self, Item *which)
{
  for (int i = 0; i < 4; i++) {
    if (which == 0 || which == self->items[i]) {
      Item *it = self->items[i];
      int f = it ? it->f58 : 0;
      if (f != 0) {
        FUN_00201ca4(self, it, self->args[i], i, 8, 0);
      }
    }
  }
}
