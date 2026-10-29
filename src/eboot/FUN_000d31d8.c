/* HSTMATCH module=EBOOT.BIN start=0x000d31d8 end=0x000d3204 symbol=FUN_000d31d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000e7198();

typedef struct Child {
  char pad00[0xd0];
  u8 active;  /* 0xd0 */
} Child;

typedef struct Parent {
  char pad00[0x180];
  Child *child;  /* 0x180 */
} Parent;

/* If the child is active, run its update with 0. */
void FUN_000d31d8(Parent *self)
{
  if (self->child->active != '\0') {
    FUN_000e7198(self->child,0);
  }
}
