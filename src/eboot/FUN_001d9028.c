/* HSTMATCH module=EBOOT.BIN start=0x001d9028 end=0x001d9038 symbol=FUN_001d9028 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/handler_obj.h"

/* Clears the state and stores 6 in the field at 0x51c. */
void FUN_001d9028(HandlerObj *obj)
{
  obj->state = 0;
  obj->unk51c = 6;
}
