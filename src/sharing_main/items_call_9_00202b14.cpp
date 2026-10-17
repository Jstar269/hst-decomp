/* HSTMATCH module=hstp_trans_main.prx start=0x00202b14 end=0x00202bac symbol=FUN_00202b14 lang=c++ */
/* Clone of src/eboot/items_call_9_001f4584.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_00202b14(Obj *self, Item *which)
{
  for (int i = 0; i < 4; i++) {
    if (which == 0 || which == self->items[i]) {
      Item *it = self->items[i];
      int f = it ? it->f58 : 0;
      if (f != 0) {
        FUN_00201ca4(self, it, self->args[i], i, 9, 0);
      }
    }
  }
}
