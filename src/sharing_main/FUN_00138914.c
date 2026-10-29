/* HSTMATCH module=hstp_trans_main.prx start=0x00138914 end=0x00138954 symbol=FUN_00138914 lang=c99 */
/* Clone of src/eboot/FUN_0012d414.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Two helper-handled words of the object (only these are touched here). */
typedef struct PairHolder {
  char pad00[4];
  u32 first;            /* 0x04 */
  char pad08[4];
  u32 second;           /* 0x0c */
} PairHolder;

extern void FUN_00055be8();

/* Pass both words to the helper; the second call also gets arg. */
void FUN_00138914(PairHolder *self,u32 arg)
{
  FUN_00055be8(self->first);
  FUN_00055be8(self->second,arg);
}
