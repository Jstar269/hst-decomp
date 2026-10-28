/* HSTMATCH module=EBOOT.BIN start=0x001b9364 end=0x001b9410 symbol=FUN_001b9364 lang=c99 */
/* Clone of src/sharing_main/order_three_by_short_001c7050.c (hstclone.py tag s10170158a3r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (matching idiom: the pointer slots are swapped through an int-typed view so the compare loads are not reused); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef short *Elem;
static inline void SwapI(Elem *a, Elem *b)
{
  int *pa = (int *)a;
  int *pb = (int *)b;
  int t = *pa;
  *pa = *pb;
  *pb = t;
}

void FUN_001b9364(Elem *a, Elem *b, Elem *c)
{
  bool ge13 = !(**c > **a);
  bool ge32 = !(**b > **c);

  if (!ge13 || !ge32) {
    if (!ge13 && !ge32) {
      SwapI(a, b);
    } else {
      if (**b > **a) {
        SwapI(a, b);
      }
      if (ge13) {
        SwapI(b, c);
      } else {
        SwapI(a, c);
      }
    }
  }
}
