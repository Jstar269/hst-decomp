/* HSTMATCH module=hstp_trans_main.prx start=0x001bde64 end=0x001bdec0 symbol=FUN_001bde64 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idiom: early-return HasSlot() helper (see release_slot_handle_001c2834.c) and a pointer into the slot table for the delete-like call.
extern void FUN_00063304(int, int);
typedef struct { int slot[0x1da]; } Obj;

static inline int HasSlot(Obj *o, int idx)
{
  int ok = idx < 0x1da;
  if (!ok) return ok;
  return o->slot[idx] != 0;
}

void FUN_001bde64(Obj *o, int idx)
{
  if (HasSlot(o, idx)) {
    int *p = &o->slot[idx];
    if (*p != 0) {
      FUN_00063304(*p, 1);
      *p = 0;
    }
  }
}
