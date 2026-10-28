/* HSTMATCH module=EBOOT.BIN start=0x000655f8 end=0x0006569c symbol=FUN_000655f8 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); exact match verified; names and types await human review. */
/* Twin of tree_find_vcall_slot3_00065554.cpp / tree_find_vcall_slot5_0006569c.cpp: tree lookup by C-string key,
   then a virtual call on the found record, here returning the float at vtable slot 4 (the shared zero path
   materialises 0.0f, and the first guard's likely branch fills its delay slot with it). Same steering tricks as
   the slot3 sibling: the `pa` key copy for the frame's 28(sp) slot, the 8-byte iterator local, and the positive
   combined guard with one trailing `return 0.0f`. */
struct It { char *p; char *q; };
struct Obj { virtual void vfn0(); virtual void vfn1(); virtual float vfn2(); };
extern "C" int FUN_00065c60(It *it, char *map, void *arg);
extern "C" float FUN_000655f8(char *self, int key, void *arg)
{
  void *pa = arg;
  It it;
  int idx;
  FUN_00065c60(&it, self + 32, &pa);
  if (it.p != self + 36) { idx = *(int *)(it.p + 16); } else { idx = -1; }
  if (key >= 0 && idx >= 0) { return (*(Obj ***)(*(char **)(self + 4) + 12 * key))[idx]->vfn2(); }
  return 0.0f;
}
