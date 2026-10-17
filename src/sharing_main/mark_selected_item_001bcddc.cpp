/* HSTMATCH module=hstp_trans_main.prx start=0x001bcddc end=0x001bcee4 symbol=FUN_001bcddc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: `Sub *sub = &o->sub;` kept in a local (used only at the end) is what keeps retail's `addiu s1,s0,28` and the later `lw v1,4(s1)`; reading o->sub.list directly at the end gives 36 words off. `opt_strength_reduction off` keeps the per-pass `sll i,2` of the loop; the clamp takes lo/hi by const reference (retail reloads the globals, cf. clamped_index_00164c60.cpp). */
#pragma opt_strength_reduction off
struct List { char pad[0x10]; int **data; int count; };
struct Sub { int pad; List *list; };
struct Obj { char pad[0x1c]; Sub sub; };
struct Self { int f0; void *f4; int f8; int fc; Obj *obj; };
struct Single { char pad[0x2c4]; int cur; };
extern "C" {
extern int DAT_00389a68;
extern int DAT_00389a6c;
extern void FUN_00105470(void *, int);
extern Single *FUN_001aa91c();
extern int FUN_001b1fa8(Single *, int);
extern void FUN_001b7b24(void *);
}
inline int Clamp(int v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_001bcddc(Self *self)
{
  FUN_001b7b24(self->f4);
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
  *sub->list->data[sel] = 0x80808080;
}
