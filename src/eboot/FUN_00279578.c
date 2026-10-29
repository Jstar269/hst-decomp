/* HSTMATCH module=EBOOT.BIN start=0x00279578 end=0x002795dc symbol=FUN_00279578 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained the four-case switch and typed its table as a member array; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_menu.h"

extern char DAT_002fe648[]; /* "Error, GetScroll(%d)\n" */
extern void FUN_0026f7f4();

/* Returns the scroll value for `mode` (1..4), 0 for any other. */
u32 FUN_00279578(ModeMenu *self,int mode)
{
  u32 result;

  switch (mode) {
    case 1:
    case 2:
    case 3:
    case 4:
      result = self->scroll[mode - 1];
      break;
    default:
      FUN_0026f7f4(DAT_002fe648);
      result = 0;
  }
  return result;
}
