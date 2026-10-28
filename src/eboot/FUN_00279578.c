/* HSTMATCH module=EBOOT.BIN start=0x00279578 end=0x002795dc symbol=FUN_00279578 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained the four-case switch and typed its table as a member array; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_002fe648[];
extern void FUN_0026f7f4();

typedef struct {
  char pad[0x134];
  u32 values[5];
} Obj;

u32 FUN_00279578(Obj *param_1,int param_2)
{
  u32 result;

  switch (param_2) {
    case 1:
    case 2:
    case 3:
    case 4:
      result = param_1->values[param_2];
      break;
    default:
      FUN_0026f7f4(DAT_002fe648);
      result = 0;
  }
  return result;
}
