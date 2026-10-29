/* HSTMATCH module=hstp_trans_main.prx start=0x000d6e34 end=0x000d6e60 symbol=FUN_000d6e34 lang=c99 */
/* Clone of src/eboot/FUN_000d31d8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000ec194();

typedef struct Child {
  char pad00[0xd0];
  u8 active;  /* 0xd0 */
} Child;

typedef struct Parent {
  char pad00[0x180];
  Child *child;  /* 0x180 */
} Parent;

/* If the child is active, run its update with 0. */
void FUN_000d6e34(Parent *self)
{
  if (self->child->active != '\0') {
    FUN_000ec194(self->child,0);
  }
}
