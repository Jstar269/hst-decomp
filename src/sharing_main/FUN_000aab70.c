/* HSTMATCH module=hstp_trans_main.prx start=0x000aab70 end=0x000aaba8 symbol=FUN_000aab70 lang=c99 */
/* Clone of src/eboot/FUN_000a817c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object with two words at 0x144 and 0x148 handed to a helper. */
typedef struct PairObj {
  char pad00[0x144];
  u32 unk144;               /* 0x144 */
  u32 unk148;               /* 0x148 */
} PairObj;

extern u32 DAT_003e1e84;
extern void FUN_000e0924();
extern void FUN_000e0a10();

/* Passes the two words to the helper for the global handle, then calls the second helper on it. */
void FUN_000aab70(PairObj *self)
{
  FUN_000e0a10(DAT_003e1e84,self->unk144,self->unk148);
  FUN_000e0924(DAT_003e1e84);
}
