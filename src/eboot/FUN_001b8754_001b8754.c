/* HSTMATCH module=EBOOT.BIN start=0x001b8754 end=0x001b87e8 symbol=FUN_001b8754 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/toggle_obj.h"

extern int DAT_0034179c;
extern void FUN_001b4240(int *, float);
extern void FUN_001b4464(int *, int);

/* Switches the object on or off; the shared object is told once per transition (and faded on turn-off). */
void FUN_001b8754(ToggleObj *self, int on)
{
  if (on != 0 && self->off != 0) {
    FUN_001b4464(&DAT_0034179c, on);
  }
  else if (on == 0) {
    if (self->off == 0) {
      FUN_001b4464(&DAT_0034179c, on);
      FUN_001b4240(&DAT_0034179c, 0.5f);
    }
  }
  self->off = ((on != 0) ^ 1);
}
