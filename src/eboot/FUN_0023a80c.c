/* HSTMATCH module=EBOOT.BIN start=0x0023a80c end=0x0023a830 symbol=FUN_0023a80c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/hist_obj.h"

/* Global record with a divisor at 0x18b8. */
typedef struct Timing {
  char pad00[0x18b8];
  int unk18b8;  /* 0x18b8 */
} Timing;

extern Timing * DAT_0034a6bc;

/* True when the counter divided by the global divisor is odd. */
bool FUN_0023a80c(HistObj *self)
{
  return (self->unk1850 / DAT_0034a6bc->unk18b8 & 1U) != 0;
}
