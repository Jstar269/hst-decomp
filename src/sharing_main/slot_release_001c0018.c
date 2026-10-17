/* HSTMATCH module=hstp_trans_main.prx start=0x001c0018 end=0x001c00d4 symbol=FUN_001c0018 lang=c99 */
/* Clone of src/eboot/slot_release_001b1f84.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Earlier near miss wip/slot_release_001c0018.c (registers only) fixed by the inline early-return HasSlot() form with the identical-layout Obj2 view for the reload, see release_slot_handle_001b4848.c. */
extern void FUN_000637c8();
extern void FUN_00063890();
extern int FUN_001c04cc();

typedef struct Obj { int slots[0x1eb]; int cur; int idx; } Obj;
typedef struct Obj2 { int slots[0x1eb]; int cur; int idx; } Obj2;

static inline int HasSlot(Obj *o)
{
  int ok = o->idx < 0x1da;
  if (!ok) return ok;
  return o->slots[o->idx] != 0;
}

int FUN_001c0018(Obj **param_1, int *param_2)
{
  Obj *o;
  int a;

  if (FUN_001c04cc(param_1, param_2) == 0) {
    return 0;
  }
  o = *param_1;
  a = o->cur;
  if (*param_2 == a) {
    if (HasSlot(o)) {
      if (a >= 0) {
        FUN_000637c8(o->slots[((Obj2 *)o)->idx], a);
        o->cur = -1;
      }
      o->idx = 0x1da;
    }
  } else {
    FUN_00063890(*param_2);
  }
  *param_2 = -1;
  return 1;
}
