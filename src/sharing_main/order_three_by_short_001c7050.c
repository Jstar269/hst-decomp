/* HSTMATCH module=hstp_trans_main.prx start=0x001c7050 end=0x001c70fc symbol=FUN_001c7050 lang=c99 */
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

void FUN_001c7050(Elem *a, Elem *b, Elem *c)
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
