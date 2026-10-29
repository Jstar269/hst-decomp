/* HSTMATCH module=hstp_trans_main.prx start=0x002be928 end=0x002be938 symbol=FUN_002be928 lang=c99 */
/* Clone of src/eboot/FUN_002af0a4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct GlobalBlock {
  char pad0000[0x1414];
  float value;          /* 0x1414 */
} GlobalBlock;

extern GlobalBlock * DAT_003ea8e8;
extern u64 FUN_001ca418(float value);

/* Call the helper with the float at +0x1414 of the global block and return its result. */
u64 FUN_002be928(void)
{
  u64 result;
  
  result = FUN_001ca418(DAT_003ea8e8->value);
  return result;
}
