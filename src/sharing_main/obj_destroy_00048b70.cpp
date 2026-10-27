/* HSTMATCH module=hstp_trans_main.prx start=0x00048b70 end=0x00048bec symbol=FUN_00048b70 lang=c++ */
/* Clone of src/eboot/obj_destroy_00048e7c.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane km1 near miss, finished by lane wf20261026-e01-03: the third callee argument is an empty tag passed by value, `move v0,zero; seb a2,v0`); the duplicated `self != 0` tests stand for inlined destructor null checks (matching idiom: repeated null test); exact match verified; names and types await human review. */
struct Obj {
  void *f0;
  int f4;
};

struct Tag {};
extern "C" void FUN_00048bec(Obj *, int, Tag);
extern "C" void FUN_00000a00(void *);

static inline void Free(void *p, Tag)
{
  FUN_00000a00(p);
}

extern "C" Obj *FUN_00048b70(Obj *self, short flag)
{
  if (self != 0) {
    if (self != 0 && self != 0) {
      FUN_00048bec(self, self->f4, Tag());
      if (self->f0 != 0) {
        Free(self->f0, Tag());
      }
    }
    if (flag > 0) {
      Free(self, Tag());
    }
  }
  return self;
}
