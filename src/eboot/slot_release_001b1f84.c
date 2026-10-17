/* HSTMATCH module=EBOOT.BIN start=0x001b1f84 end=0x001b2040 symbol=FUN_001b1f84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Earlier near miss wip/slot_release_001b1f84.c (registers only) fixed by the inline early-return HasSlot() form with the identical-layout Obj2 view for the reload, see release_slot_handle_001b4848.c. */
extern void FUN_00062904();
extern void FUN_000629cc();
extern int FUN_001b2438();

typedef struct Obj { int slots[0x1eb]; int cur; int idx; } Obj;
typedef struct Obj2 { int slots[0x1eb]; int cur; int idx; } Obj2;

static inline int HasSlot(Obj *o)
{
  int ok = o->idx < 0x1da;
  if (!ok) return ok;
  return o->slots[o->idx] != 0;
}

int FUN_001b1f84(Obj **param_1, int *param_2)
{
  Obj *o;
  int a;

  if (FUN_001b2438(param_1, param_2) == 0) {
    return 0;
  }
  o = *param_1;
  a = o->cur;
  if (*param_2 == a) {
    if (HasSlot(o)) {
      if (a >= 0) {
        FUN_00062904(o->slots[((Obj2 *)o)->idx], a);
        o->cur = -1;
      }
      o->idx = 0x1da;
    }
  } else {
    FUN_000629cc(*param_2);
  }
  *param_2 = -1;
  return 1;
}
