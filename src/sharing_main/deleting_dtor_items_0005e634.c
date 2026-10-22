/* HSTMATCH module=hstp_trans_main.prx start=0x0005e634 end=0x0005e6e0 symbol=FUN_0005e634 lang=c99 */
/* Clone of src/eboot/deleting_dtor_items_0005d818.c (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor of an object holding a pointer array: every element is destroyed through
   FUN_0005dc04(elem, 1), the member at +0 is destroyed through FUN_000104e0, the vector-like member
   at +4 through FUN_0005eac0 (behind a doubled null test on its address, as in destroy_buffers_0005dc04.c),
   and a positive flag deletes the object. Names provisional. */
typedef unsigned int uint;

extern void FUN_00000a00(void *);
extern void FUN_000104e0(void *);
extern void FUN_0005dc04(void *, int);
extern void FUN_0005eac0(void *, int);

typedef struct {
  void *f0;
  void **items;
  uint count;
} Obj;

#pragma opt_strength_reduction off
Obj *FUN_0005e634(Obj *self, short flag)
{
  char *p;
  uint i;
  if (self != 0) {
    for (i = 0; i < self->count; i++) {
      FUN_0005dc04(self->items[i], 1);
    }
    FUN_000104e0(self->f0);
    p = (char *)self + 4;
    if (p != 0) {
      if (p != 0) {
        FUN_0005eac0(p, 0);
      }
    }
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
