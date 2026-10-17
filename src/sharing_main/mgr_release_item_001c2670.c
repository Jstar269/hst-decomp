/* HSTMATCH module=hstp_trans_main.prx start=0x001c2670 end=0x001c26e0 symbol=FUN_001c2670 lang=c99 */
/* Clone of src/eboot/mgr_release_item_001b464c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Earlier near miss wip/mgr_release_item_001c2670.c (registers only) fixed by the inline early-return HasSlot() form, see release_slot_handle_001b4848.c. */
typedef struct Obj { int tab[0x1ef]; int handle; int idx; } Obj;
typedef struct Obj2 { int tab[0x1ef]; int handle; int idx; } Obj2;
extern void FUN_00063810(int, int);

static inline int HasSlot(Obj *o)
{
  int ok = o->idx < 0x1da;
  if (!ok) return ok;
  return o->tab[o->idx] != 0;
}

void FUN_001c2670(Obj **param_1)
{
  Obj *o = *param_1;
  if (HasSlot(o) && o->handle >= 0) {
    FUN_00063810(o->tab[((Obj2 *)o)->idx], o->handle);
    o->handle = -1;
  }
}
