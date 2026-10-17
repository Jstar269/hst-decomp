/* HSTMATCH module=EBOOT.BIN start=0x001b4074 end=0x001b40d8 symbol=FUN_001b4074 lang=c99 */
/* Clone of src/sharing_main/call_slot_handler_001c21b8.c (hstclone.py tag s10170158a4r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00062cb4(int);
typedef struct { int slot[0x1da]; } Obj;

static inline int HasSlot(Obj *o, int idx)
{
  int ok = idx < 0x1da;
  if (!ok) return ok;
  return o->slot[idx] != 0;
}

void FUN_001b4074(Obj **p, int idx)
{
  Obj *o = *p;
  int ok = idx >= 0;
  if (ok) ok = idx < 50;
  if (ok && HasSlot(o, idx)) {
    FUN_00062cb4(o->slot[idx]);
  }
}
