/* HSTMATCH module=EBOOT.BIN start=0x001b47d8 end=0x001b4848 symbol=FUN_001b47d8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00062904(int, int);

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

void FUN_001b47d8(Obj **p)
{
  Obj *o = *p;
  if (HasSlot(o) && o->handle >= 0) {
    FUN_00062904(o->slot[((Obj2 *)o)->idx], o->handle);
    o->handle = -1;
  }
}
