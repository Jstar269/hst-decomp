/* HSTMATCH module=hstp_trans_main.prx start=0x001bcfbc end=0x001bd0cc symbol=FUN_001bcfbc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Same shape as mark_selected_item_001bcddc.cpp (loop, clamp by const reference, `Sub *sub = &o->sub;` kept in a local); only the tail differs.
#pragma opt_strength_reduction off
struct List { char pad[0x10]; int **data; int count; };
struct Sub { int pad; List *list; int val; };
struct Obj { char pad[0x1c]; Sub sub; };
struct Self { int f0; void *f4; int f8; int fc; Obj *obj; };
struct Single { char pad[0x2c4]; int cur; };
extern "C" {
extern int DAT_00389a68;
extern int DAT_00389a6c;
extern void FUN_00105470(void *, int);
extern Single *FUN_001aa91c();
extern int FUN_001b1fa8(Single *, int);
extern void FUN_001ba5cc(int, int);
}
inline int Clamp(int v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_001bcfbc(Self *self)
{
  Obj *o = self->obj;
  Single *a = FUN_001aa91c();
  Single *b = FUN_001aa91c();
  int n = FUN_001b1fa8(b, a->cur);
  int sel = Clamp(n - 1, DAT_00389a68, DAT_00389a6c);
  Sub *sub = &o->sub;
  List *l = o->sub.list;
  int i = 0;
  if (l->count > 0) {
    do {
      FUN_00105470(l->data[i], i != sel);
      i++;
    } while (i < l->count);
  }
  *sub->list->data[sel] = sub->val;
  FUN_001ba5cc(self->fc, 1);
}
