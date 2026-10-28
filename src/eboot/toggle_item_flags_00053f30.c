/* HSTMATCH module=EBOOT.BIN start=0x00053f30 end=0x00054010 symbol=FUN_00053f30 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Walks the two nested lists of a scene object (the list head is the member at +8 plus 0x10) and sets or
   clears bit 0x10 of the flag u8 at +0x33 of every leaf item, depending on the mode argument.
   Names provisional. */
#include "hst/types.h"

extern int FUN_0002e840(void *);
extern void *FUN_0002e650(void *, int);
extern int FUN_0002e40c(void *);
extern void *FUN_0002e3d0(void *, int);

typedef struct {
  char pad[0x33];
  u8 flags;
} Item;

void FUN_00053f30(void *self, int mode)
{
  void *arr;
  int n;
  int i;
  void *elem;
  int m;
  int j;
  void *slot;
  Item *it;
  arr = (char *)*(void **)((char *)self + 8) + 0x10;
  n = FUN_0002e840(arr);
  i = 0;
  while (i < n) {
    elem = FUN_0002e650(arr, i);
    m = FUN_0002e40c(elem);
    j = 0;
    while (j < m) {
      slot = FUN_0002e3d0(elem, j);
      it = *(Item **)slot;
      if (mode != 0) {
        it->flags |= 0x10;
      } else {
        it->flags &= 0xef;
      }
      j++;
    }
    i++;
  }
}
