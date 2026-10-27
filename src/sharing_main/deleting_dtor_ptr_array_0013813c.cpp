/* HSTMATCH module=hstp_trans_main.prx start=0x0013813c end=0x00138254 symbol=FUN_0013813c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor: two vtable stores (main object, sub-object at +0x1320), delete of ten owned pointers whose class has a
   4-byte non-polymorphic base (vptr at +4), release of a global and of the +0x1398 member, then the sub-object and base
   destructors (flag 0) and operator delete for flag > 0. The ten deletes go through an inline for_each with an empty
   DeleteObject functor taken by value: its never-written slot gives retail's 32-byte frame (a plain loop gives 16). */
struct VB_0 { int x; };
struct VC_4 : VB_0 { virtual ~VC_4(); };
struct VC_0 { virtual ~VC_0(); };
struct Obj {
  void *vptr;
  char pad4[0x1320 - 4];
  void *vptr2;
  char pad1324[0x1398 - 0x1324];
  VC_0 *f1398;
  char pad139c[0x13a0 - 0x139c];
  VC_4 *arr[10];
};
extern "C" {
extern char DAT_003b13d4;
extern char DAT_003b13f0;
extern void *DAT_003e1a54;
extern int DAT_003e48b4;
extern void FUN_0005c688(void *p, int v);
extern void FUN_0014c3a4(Obj *self);
extern void *FUN_00297f98(void *self, short flag);
extern void *FUN_0014be3c(void *self, short flag);
extern void FUN_00000a00(void *p);
}
struct DeleteObject {
  void operator()(VC_4 *p) const { delete p; }
};
template <class It, class F> inline F ForEach(It first, It last, F f)
{
  for (; first != last; ++first)
    f(*first);
  return f;
}
extern "C" Obj *FUN_0013813c(Obj *self, short flag)
{
  if (self != 0) {
    self->vptr = &DAT_003b13d4;
    self->vptr2 = &DAT_003b13f0;
    ForEach(self->arr, self->arr + 10, DeleteObject());
    if (DAT_003e1a54 != 0) {
      FUN_0005c688(DAT_003e1a54, 1);
      DAT_003e1a54 = 0;
    }
    if (self->f1398 != 0) {
      delete self->f1398;
      self->f1398 = 0;
    }
    FUN_0014c3a4(self);
    DAT_003e48b4 = 0;
    FUN_00297f98(&self->vptr2, 0);
    FUN_0014be3c(self, 0);
    if (flag > 0)
      FUN_00000a00(self);
  }
  return self;
}
