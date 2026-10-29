/* HSTMATCH module=EBOOT.BIN start=0x00204394 end=0x00204400 symbol=FUN_00204394 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: used a typed C++ virtual method call; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 * DAT_0034a148;
extern int * DAT_0034a14c;
extern void FUN_000009e4(void *);
void FUN_00204394(void);
}

/* Object with a virtual deleting destructor in the first slot. */
struct Deletable { virtual void destroy(int flags); };

#define ARRAY_HEADER_SIZE 0x10

/* Frees the character-select parameter table and deletes its loader object. */
extern "C" void FUN_00204394(void)
{
  if (DAT_0034a148 != 0) {
    if (DAT_0034a148 != 0) {
      FUN_000009e4(DAT_0034a148 + -ARRAY_HEADER_SIZE);
    }
    DAT_0034a148 = 0;
  }
  if (DAT_0034a14c != (int *)0x0) {
    if (DAT_0034a14c != (int *)0x0) {
      ((Deletable *)DAT_0034a14c)->destroy(1);
    }
    DAT_0034a14c = (int *)0x0;
  }
}
