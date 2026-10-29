/* HSTMATCH module=EBOOT.BIN start=0x00199280 end=0x00199310 symbol=FUN_00199280 lang=c99 rodata=0x002c2aac */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0r) corrected by hand: the switch cases are written in retail body order (2, 4, 5, 3, 9, 10); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct InstallSetup {
  char pad00[4];
  u32 kind;                /* 0x04 */
  u32 enabled;             /* 0x08 */
} InstallSetup;

extern u32 DAT_003417a4;

/* Enable the setup and copy the global mode to `kind` for modes 2 to 5, 9 and 10 (any other mode gives 1). */
void FUN_00199280(InstallSetup *self)
{
  self->enabled = 1;
  switch(DAT_003417a4) {
  case 0:
  case 1:
  case 6:
  case 7:
  case 8:
  default:
    self->kind = 1;
    break;
  case 2:
    self->kind = 2;
    break;
  case 4:
    self->kind = 4;
    break;
  case 5:
    self->kind = 5;
    break;
  case 3:
    self->kind = 3;
    break;
  case 9:
    self->kind = 9;
    break;
  case 10:
    self->kind = 10;
  }
}
