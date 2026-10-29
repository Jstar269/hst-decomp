/* HSTMATCH module=hstp_trans_main.prx start=0x001e1e80 end=0x001e1e8c symbol=FUN_001e1e80 lang=c99 */
/* Clone of src/eboot/FUN_001d407c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct PairObj {
  char pad0[0x24];
  u32 unk24;  /* 0x24 */
  u32 unk28;  /* 0x28 */
} PairObj;

/* Store the same value in both fields. */
void FUN_001e1e80(PairObj *self,u32 value)
{
  self->unk24 = value;
  self->unk28 = value;
}
