/* HSTMATCH module=EBOOT.BIN start=0x001b48b8 end=0x001b492c symbol=FUN_001b48b8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the float parameter passed through (mov.s $f12,$f13 in the call delay slot; Ghidra misread the register parameters), the slot test as an inline early-return HasSlot() and the reload of idx forced through an identical-layout struct view, as in release_slot_handle_001b4848.c; exact match verified; names and types await human review. */
extern "C" void FUN_0006294c(int, int, float);

struct Obj {
  int slot[0x1f1];
  int handle;
  int idx;
};

/* identical layout, different type: forces the reload of idx that retail has */
struct Obj2 {
  int slot[0x1f1];
  int handle;
  int idx;
};

static inline int HasSlot(Obj *o)
{
  int ok = o->idx < 0x1da;
  if (!ok) return ok;
  return o->slot[o->idx] != 0;
}

struct Self { Obj *o; };

extern "C" void FUN_001b48b8(Self *p, float a, float t)
{
  Obj *o = p->o;
  if (HasSlot(o) && o->handle >= 0) {
    FUN_0006294c(o->slot[((Obj2 *)o)->idx], o->handle, t);
    o->handle = -1;
  }
}
