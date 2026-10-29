/* HSTMATCH module=EBOOT.BIN start=0x001dd260 end=0x001dd28c symbol=FUN_001dd260 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/main_result_obj.h"

extern void FUN_00103128();
extern void FUN_001eab5c();

void FUN_001dd260(MainResultObj *self)
{
  FUN_00103128();
  FUN_001eab5c(self->unk8c);
}
