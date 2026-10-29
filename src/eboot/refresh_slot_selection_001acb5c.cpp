/* HSTMATCH module=EBOOT.BIN start=0x001acb5c end=0x001acc30 symbol=FUN_001acb5c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5, variant v17) corrected by hand: the loop bound read through a pointer to the sub-object at +0x360 (reloaded each iteration), the element address written (param_1 + (offset + 0x7bc)) + 9 words, locals declared counter/selected/offset; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_000ffb3c(...);
extern void FUN_0010b980(...);
extern u32 FUN_0019d474(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct List { int pad; unsigned size; };
struct Obj { char pad[0x360]; List l; };

/* Calls the row handler with 0 for the row matching the selected index (read from the state object) and 1 for every other row; when `redirect` is set the panel is first told the selection. */
extern "C" void FUN_001acb5c(int self,int redirect)
{
  int state;
  int *handle;
  List *pl;
  unsigned i;
  unsigned selected;
  int offset;

  state = FUN_0019d474();
  selected = *(unsigned *)(state + 0x2dc);
  if (redirect != 0) {
    ((VC_0 *)(*(int **)(self + 0x914)))->m((int)(0));
    FUN_0010b980(*(u32 *)(self + 0x914),selected,0);
  }
  state = FUN_0019d474();
  pl = (List *)(state + 0x360);
  i = 0;
  if (*(int *)(state + 0x364) != 0) {
    offset = 0;
    do {
      handle = (int *)(self + (offset + 0x7bc)) + 9;
      if (selected == i) {
        FUN_000ffb3c(*handle,0);
      }
      else {
        FUN_000ffb3c(*handle,1);
      }
      i = i + 1;
      offset = offset + 0x14;
    } while (i < pl->size);
  }
}
