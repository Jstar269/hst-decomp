/* HSTMATCH module=EBOOT.BIN start=0x00057730 end=0x00057838 symbol=FUN_00057730 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Clears the two per-item records of every entry of the item array (id set to -1, speed 0.0f) and
   destroys the entry's buffer object.  Layout: 0xe0 = item pointer array, 0xe4 = entry count,
   0xf0 + k*0x34 = the two records of an item (0x00 = id, 0x20 = state id). */
/* matching idiom: the loop-head count read uses a second type view of the same member (cast to an
   identical struct) and the array store indexes with a differently typed index, so that MWCC does
   not common the two loads/computations; the item pointer is tested twice (nested if) before the
   destructor call. */
#include "hst/types.h"

extern void FUN_00057b58(float, int, int, int);
extern void FUN_00057bc0(float, int, int, int, float, float);
extern void FUN_000561d4(void *, int);

typedef struct {
  char pad0[0xe0];
  void **fE0;
  u32 fE4;
  char padE8[8];
  char padF0[0x114 - 0xf0];
} Obj;

typedef struct {
  char pad0[0xe0];
  void **fE0;
  int fE4;
  char padE8[8];
  char padF0[0x114 - 0xf0];
} ObjInt;

#pragma opt_strength_reduction off
void FUN_00057730(Obj *self)
{
  u32 i = 0;
  if (self->fE4 != 0) {
    do {
      if ((int)i < 0) {
      } else if (i < (u32)((ObjInt *)self)->fE4) {
        u32 j = 0;
        char *p = (char *)self;
        while (j < 2) {
          if (*(u32 *)(p + 0xf0) == i) {
            FUN_00057b58(0.0f, (int)self, (int)j, -1);
          }
          if (*(u32 *)(p + 0x110) == i) {
            FUN_00057bc0(0.0f, (int)self, (int)j, -1, 0.0f, 0.0f);
          }
          p += 0x34;
          j++;
        }
        {
          void *q = self->fE0[i];
          if (q != 0) {
            if (q != 0) {
              FUN_000561d4(q, 1);
              self->fE0[(int)i] = 0;
            }
          }
        }
      }
      i++;
    } while (i < self->fE4);
  }
}
