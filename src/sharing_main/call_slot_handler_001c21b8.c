/* HSTMATCH module=hstp_trans_main.prx start=0x001c21b8 end=0x001c221c symbol=FUN_001c21b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idiom: the range test is `int ok = idx >= 0; if (ok) ok = idx < 50;` (retail slt/xori then slti) followed by the early-return HasSlot() helper.
extern void FUN_00063b78(int);
typedef struct { int slot[0x1da]; } Obj;

static inline int HasSlot(Obj *o, int idx)
{
  int ok = idx < 0x1da;
  if (!ok) return ok;
  return o->slot[idx] != 0;
}

void FUN_001c21b8(Obj **p, int idx)
{
  Obj *o = *p;
  int ok = idx >= 0;
  if (ok) ok = idx < 50;
  if (ok && HasSlot(o, idx)) {
    FUN_00063b78(o->slot[idx]);
  }
}
