/* HSTMATCH module=EBOOT.BIN start=0x00065554 end=0x000655f8 symbol=FUN_00065554 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); exact match verified; names and types await human review. */
/* Tree lookup by C-string key (tree_find_cstr_00065c60 on the tree at self+32, end = its root at self+36),
   then a virtual call on the record it found. Siblings with the identical body: tree_find_vcall_slot4_000655f8.cpp
   (float, vtable slot 4) and tree_find_vcall_slot5_0006569c.cpp (int, slot 5); only the slot and return type differ.
   Steering tricks: (a) the `pa` copy of the key argument — the address-taken key must land at 28(sp), above the
   iterator, which the raw `&arg` spelling does not do; (b) the iterator local is declared 8 bytes even though
   tree_find_cstr_00065c60 writes only its first word, because retail's iterator occupies 20..28; (c) the guard
   is the positive combined test with a single trailing `return 0` — the two-return spelling puts the zero in
   its own block and misses by a word. */
struct It { char *p; char *q; };
struct Obj { virtual void vfn0(); virtual int vfn1(); };
extern "C" int FUN_00065c60(It *it, char *map, void *arg);
extern "C" int FUN_00065554(char *self, int key, void *arg)
{
  void *pa = arg;
  It it;
  int idx;
  FUN_00065c60(&it, self + 32, &pa);
  if (it.p != self + 36) { idx = *(int *)(it.p + 16); } else { idx = -1; }
  if (key >= 0 && idx >= 0) { return (*(Obj ***)(*(char **)(self + 4) + 12 * key))[idx]->vfn1(); }
  return 0;
}
