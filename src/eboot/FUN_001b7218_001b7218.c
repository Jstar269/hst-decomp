/* HSTMATCH module=EBOOT.BIN start=0x001b7218 end=0x001b7298 symbol=FUN_001b7218 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: symbol-address and pointer/float helper prototypes; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/inst_obj.h"

extern void FUN_001b2430(int *param_1);
extern void FUN_001b3ea4(int *param_1, float param_2);
extern void FUN_001b4240(int *param_1, float param_2);
extern void FUN_001b464c(int *param_1, float param_2);
extern void FUN_001b871c();
extern int DAT_0034179c;

void FUN_001b7218(InstObj *self)
{
  FUN_001b871c();
  self->unk78 = 1;
  FUN_001b3ea4(&DAT_0034179c,0.1f);
  FUN_001b4240(&DAT_0034179c,0.1f);
  FUN_001b464c(&DAT_0034179c,0.1f);
  FUN_001b2430(&DAT_0034179c);
}
