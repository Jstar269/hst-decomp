/* HSTMATCH module=EBOOT.BIN start=0x0006569c end=0x00065740 symbol=FUN_0006569c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); exact match verified; names and types await human review. */
/* Third twin of the family (see tree_find_vcall_slot3_00065554.cpp): identical lookup and frame; calls vtable
   slot 5 and returns its int. Same steering tricks: `pa` key copy, 8-byte iterator local, positive combined
   guard with a single trailing `return 0`. */
struct It { char *p; char *q; };
struct Obj { virtual void vfn0(); virtual void vfn1(); virtual void vfn2(); virtual int vfn3(); };
extern "C" int FUN_00065c60(It *it, char *map, void *arg);
extern "C" int FUN_0006569c(char *self, int key, void *arg)
{
  void *pa = arg;
  It it;
  int idx;
  FUN_00065c60(&it, self + 32, &pa);
  if (it.p != self + 36) { idx = *(int *)(it.p + 16); } else { idx = -1; }
  if (key >= 0 && idx >= 0) { return (*(Obj ***)(*(char **)(self + 4) + 12 * key))[idx]->vfn3(); }
  return 0;
}
