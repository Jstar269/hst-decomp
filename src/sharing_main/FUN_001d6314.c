/* HSTMATCH module=hstp_trans_main.prx start=0x001d6314 end=0x001d6320 symbol=FUN_001d6314 lang=c99 */
/* Clone of src/eboot/FUN_001c7e80.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct PairHolder {
  char pad00[0x14c];
  u32 unk14c; /* 0x14c */
  u32 unk150; /* 0x150 */
} PairHolder;

/* Stores two words. */
void FUN_001d6314(PairHolder *self,u32 a,u32 b)
{
  self->unk14c = a;
  self->unk150 = b;
}
