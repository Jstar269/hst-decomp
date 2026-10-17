/* HSTMATCH module=hstp_trans_main.prx start=0x001c28a4 end=0x001c2914 symbol=FUN_001c28a4 lang=c99 */
/* Clone of src/eboot/release_slot_handle_001b47d8.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00063810(int, int);

typedef struct Obj {
  int slot[0x1f1];
  int handle;
  int idx;
} Obj;

/* identical layout, different type: forces the reload of idx that retail has */
typedef struct Obj2 {
  int slot[0x1f1];
  int handle;
  int idx;
} Obj2;

static inline int HasSlot(Obj *o)
{
  int ok = o->idx < 0x1da;
  if (!ok) return ok;
  return o->slot[o->idx] != 0;
}

void FUN_001c28a4(Obj **p)
{
  Obj *o = *p;
  if (HasSlot(o) && o->handle >= 0) {
    FUN_00063810(o->slot[((Obj2 *)o)->idx], o->handle);
    o->handle = -1;
  }
}
