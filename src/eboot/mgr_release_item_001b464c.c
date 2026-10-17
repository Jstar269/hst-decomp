/* HSTMATCH module=EBOOT.BIN start=0x001b464c end=0x001b46bc symbol=FUN_001b464c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Earlier near miss wip/mgr_release_item_001b464c.c (registers only) fixed by the inline early-return HasSlot() form, see release_slot_handle_001b4848.c. */
typedef struct Obj { int tab[0x1ef]; int handle; int idx; } Obj;
typedef struct Obj2 { int tab[0x1ef]; int handle; int idx; } Obj2;
extern void FUN_0006294c(int, int);

static inline int HasSlot(Obj *o)
{
  int ok = o->idx < 0x1da;
  if (!ok) return ok;
  return o->tab[o->idx] != 0;
}

void FUN_001b464c(Obj **param_1)
{
  Obj *o = *param_1;
  if (HasSlot(o) && o->handle >= 0) {
    FUN_0006294c(o->tab[((Obj2 *)o)->idx], o->handle);
    o->handle = -1;
  }
}
