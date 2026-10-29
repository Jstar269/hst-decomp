/* HSTMATCH module=hstp_trans_main.prx start=0x001a8658 end=0x001a8688 symbol=FUN_001a8658 lang=c99 */
/* Clone of src/eboot/FUN_0019b460.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ClearedObj {
  char pad0[0x130];
  u32 unk130; /* 0x130 */
  u32 unk134; /* 0x134 */
  u32 unk138; /* 0x138 */
} ClearedObj;

extern void FUN_0011177c();

/* Runs the helper, then clears three words. */
void FUN_001a8658(ClearedObj *self)
{
  FUN_0011177c();
  self->unk138 = 0;
  self->unk130 = 0;
  self->unk134 = 0;
}
