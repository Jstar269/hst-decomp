/* HSTMATCH module=hstp_trans_main.prx start=0x0005c280 end=0x0005c2f8 symbol=FUN_0005c280 lang=c++ */
/* Clone of src/eboot/dtor_free_item_0005b5f8.cpp (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor: clears the counter member at +4, frees the sub-object at +0 when it is not
   null, frees the object itself when the flag argument is positive and returns the object.
   Matching idioms: the null-check trio (beqz / beqzl / beqz) comes from the outer guard plus the
   doubled "self != 0" test of the inner block; clearing the member needs the int cast
   ("int n = (int)m; m -= n;") to keep retail's load / subu / store instead of a plain sw zero;
   the hidden 16-byte frame slot comes from an inline wrapper taking an empty tag by value.
   Names provisional. */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
/* Deleting destructor: clears the pointer member at +4, frees the sub-object at +0 when it is not
   null, frees the object itself when the flag argument is positive and returns the object.
   The null-check trio (beqz / beqzl / beqz) comes from the outer guard plus the doubled
   "self != 0" test of the inner block.
   Names provisional. */
extern "C" void FUN_00000a00(void *);

struct Tag {};

static inline void Free(void *p, Tag)
{
  FUN_00000a00(p);
}

typedef struct {
  void *f0;
  int f4;
} Obj;

extern "C" Obj *FUN_0005c280(Obj *self, short flag)
{
  if (self != 0) {
    if (self != 0 && self != 0) {
      {
        int n = (int)self->f4;
        self->f4 -= n;
      }
      if (self->f0 != 0) {
        Free(self->f0, Tag());
      }
    }
    if (flag > 0) {
      Free(self, Tag());
    }
  }
  return self;
}
