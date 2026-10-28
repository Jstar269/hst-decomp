/* HSTMATCH module=EBOOT.BIN start=0x00065480 end=0x00065554 symbol=FUN_00065480 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); exact match verified; names and types await human review. */
/* Two-key sibling of the 0x65554 family: two tree_find_cstr_00065c60 lookups - the trees hang at self+16 and
   self+32, their sentinel roots at self+20 and self+36, and the found index (entry+16) of each bounds-checks
   the record that the other indexes; the surviving record's virtual at vtable slot 4 is returned as a float,
   0.0f otherwise. The guards are the family's positive nested test with one trailing `return 0.0f`.
   Steering tricks, all required for the frame or the scheduling:
     (a) the declared key copies `pa` (the first key) and `pb` (the second, ASSIGNED only after the first
         lookup - that is what keeps the second key in s2 across the call and stores it in the second call's
         delay slot the way retail does);
     (b) the frame is pinned by DECLARING THE OBJECTS AT RETAIL'S SLOT SIZES in declaration order: pa 4 bytes
         at 44, pb 8 bytes at 36, the first iterator 8 bytes at 28, the second 4 bytes at 24. The second key's
         slot is 8 bytes and the second iterator's only 4 even though both hold one pointer each - the slot
         SPAN is what puts them where retail has them (same lever that fixed the 0x65554 family). */
struct It8 { char *p; char *q; };
struct It4 { char *p; };
struct Obj { virtual void v0(); virtual void v1(); virtual float v2(); };
extern "C" void FUN_00065c60(void *out, char *tree, void *key);
extern "C" float FUN_00065480(char *self, void *arg, void *arg2)
{
  void *pa = arg;
  It8 pb;
  It8 it1;
  It4 it2;
  int idx1;
  int idx2;
  FUN_00065c60(&it1, self + 16, &pa);
  if (it1.p != self + 20) { idx1 = *(int *)(it1.p + 16); } else { idx1 = -1; }
  pb.p = (char *)arg2;
  FUN_00065c60(&it2, self + 32, &pb);
  if (it2.p != self + 36) { idx2 = *(int *)(it2.p + 16); } else { idx2 = -1; }
  if (idx1 >= 0 && idx2 >= 0) { return (*(Obj ***)(*(char **)(self + 4) + 12 * idx1))[idx2]->v2(); }
  return 0.0f;
}
