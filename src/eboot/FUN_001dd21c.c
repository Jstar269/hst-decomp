/* HSTMATCH module=EBOOT.BIN start=0x001dd21c end=0x001dd260 symbol=FUN_001dd21c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/main_result_obj.h"

extern void FUN_00103480();
extern void FUN_001ea8dc();
extern void FUN_001ea930();
extern void FUN_001eaa00();

void FUN_001dd21c(MainResultObj *self)
{
  FUN_00103480();
  FUN_001ea930(self->unk8c,0);
  FUN_001eaa00(self->unk8c,0);
  FUN_001ea8dc(self->unk8c);
}
