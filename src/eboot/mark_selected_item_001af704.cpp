/* HSTMATCH module=EBOOT.BIN start=0x001af704 end=0x001af80c symbol=FUN_001af704 lang=c++ */
/* Clone of src/sharing_main/mark_selected_item_001bcddc.cpp (hstclone.py tag s10170158a3r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: `Sub *sub = &o->sub;` kept in a local (used only at the end) is what keeps retail's `addiu s1,s0,28` and the later `lw v1,4(s1)`; reading o->sub.list directly at the end gives 36 words off. `opt_strength_reduction off` keeps the per-pass `sll i,2` of the loop; the clamp takes lo/hi by const reference (retail reloads the globals, cf. clamped_index_00164c60.cpp). */
#pragma opt_strength_reduction off
struct List { char pad[0x10]; int **data; int count; };
struct Sub { int pad; List *list; };
struct Obj { char pad[0x1c]; Sub sub; };
struct Self { int f0; void *f4; int f8; int fc; Obj *obj; };
struct Single { char pad[0x2c4]; int cur; };
extern "C" {
extern int DAT_002e2138;
extern int DAT_002e213c;
extern void FUN_000ffb3c(void *, int);
extern Single *FUN_0019d474();
extern int FUN_001a49dc(Single *, int);
extern void FUN_001aa558(void *);
}
inline int Clamp(int v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_001af704(Self *self)
{
  FUN_001aa558(self->f4);
  Obj *o = self->obj;
  Single *a = FUN_0019d474();
  Single *b = FUN_0019d474();
  int n = FUN_001a49dc(b, a->cur);
  int sel = Clamp(n - 1, DAT_002e2138, DAT_002e213c);
  Sub *sub = &o->sub;
  List *l = o->sub.list;
  int i = 0;
  if (l->count > 0) {
    do {
      FUN_000ffb3c(l->data[i], i != sel);
      i++;
    } while (i < l->count);
  }
  *sub->list->data[sel] = 0x80808080;
}
