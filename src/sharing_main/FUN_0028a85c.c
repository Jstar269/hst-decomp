/* HSTMATCH module=hstp_trans_main.prx start=0x0028a85c end=0x0028a8c0 symbol=FUN_0028a85c lang=c99 */
/* Clone of src/eboot/FUN_00279578.c (hstclone.py tag s10171846c1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained the four-case switch and typed its table as a member array; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_003a7370[];
extern void FUN_00280834();

typedef struct {
  char pad[0x134];
  u32 values[5];
} Obj;

u32 FUN_0028a85c(Obj *param_1,int param_2)
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
      FUN_00280834(DAT_003a7370);
      result = 0;
  }
  return result;
}
