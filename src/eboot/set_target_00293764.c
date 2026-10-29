/* HSTMATCH module=EBOOT.BIN start=0x00293764 end=0x002937b4 symbol=FUN_00293764 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else branch order; readability pass; exact match verified; names and types await human review. */
#include "hst/komono_obj.h"

extern void FUN_00057f30(ModelHolder *, int);
extern int * FUN_00288a84(int);

/* Stores the target and forwards its +0x58 value (0 when cleared) to the sub-object. */
void FUN_00293764(KomonoObj *obj, int target)
{
  obj->target = target;
  if (target != 0) {
    int *info = FUN_00288a84(target);
    FUN_00057f30(obj->sub, *(int *)((char *)info + 0x58));
  }
  else {
    FUN_00057f30(obj->sub, 0);
  }
}
