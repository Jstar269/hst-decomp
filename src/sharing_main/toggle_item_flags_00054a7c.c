/* HSTMATCH module=hstp_trans_main.prx start=0x00054a7c end=0x00054b5c symbol=FUN_00054a7c lang=c99 */
/* Clone of src/eboot/toggle_item_flags_00053f30.c (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Walks the two nested lists of a scene object (the list head is the member at +8 plus 0x10) and sets or
   clears bit 0x10 of the flag u8 at +0x33 of every leaf item, depending on the mode argument.
   Names provisional. */
#include "hst/types.h"

extern int FUN_0002e868(void *);
extern void *FUN_0002e678(void *, int);
extern int FUN_0002e434(void *);
extern void *FUN_0002e3f8(void *, int);

typedef struct {
  char pad[0x33];
  u8 flags;
} Item;

void FUN_00054a7c(void *self, int mode)
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
  n = FUN_0002e868(arr);
  i = 0;
  while (i < n) {
    elem = FUN_0002e678(arr, i);
    m = FUN_0002e434(elem);
    j = 0;
    while (j < m) {
      slot = FUN_0002e3f8(elem, j);
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
