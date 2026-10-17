/* HSTMATCH module=EBOOT.BIN start=0x001b04d0 end=0x001b052c symbol=FUN_001b04d0 lang=c99 */
/* Clone of src/sharing_main/release_slot_by_index_001bde64.c (hstclone.py tag s10170158a4r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00062418(int, int);
typedef struct { int slot[0x1da]; } Obj;

static inline int HasSlot(Obj *o, int idx)
{
  int ok = idx < 0x1da;
  if (!ok) return ok;
  return o->slot[idx] != 0;
}

void FUN_001b04d0(Obj *o, int idx)
{
  if (HasSlot(o, idx)) {
    int *p = &o->slot[idx];
    if (*p != 0) {
      FUN_00062418(*p, 1);
      *p = 0;
    }
  }
}
