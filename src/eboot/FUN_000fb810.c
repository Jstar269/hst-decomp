/* HSTMATCH module=EBOOT.BIN start=0x000fb810 end=0x000fb868 symbol=FUN_000fb810 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: stored and returned the field directly around the constructor call instead of keeping a separate result temporary; readability pass; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

extern int FUN_00000bcc(unsigned int);
extern int FUN_001fc31c(int, int);
extern void FUN_0001f21c(ModeScreen *, int);

#define SLOT_OBJECT_SIZE 0x58

/* Return slot 0, creating and registering the object on first use. */
int FUN_000fb810(ModeScreen *self) {
  if (self->slot[0] == 0) {
    int object = FUN_00000bcc(SLOT_OBJECT_SIZE);
    if (object != 0) object = FUN_001fc31c(object, 0);
    self->slot[0] = (void *)object;
    FUN_0001f21c(self, object);
  }
  return (int)self->slot[0];
}
