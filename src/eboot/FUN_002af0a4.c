/* HSTMATCH module=EBOOT.BIN start=0x002af0a4 end=0x002af0b4 symbol=FUN_002af0a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct GlobalBlock {
  char pad0000[0x1414];
  float value;          /* 0x1414 */
} GlobalBlock;

extern GlobalBlock * DAT_003415a8;
extern u64 FUN_001bc630(float value);

/* Call the helper with the float at +0x1414 of the global block and return its result. */
u64 FUN_002af0a4(void)
{
  u64 result;
  
  result = FUN_001bc630(DAT_003415a8->value);
  return result;
}
