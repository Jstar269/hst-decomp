/* HSTMATCH module=hstp_trans_main.prx start=0x0019cae0 end=0x0019cb14 symbol=FUN_0019cae0 lang=c99 */
/* Clone of src/eboot/FUN_001902d0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct BlockVec {
  char head[0xc];
  u32 unkc;  /* 0xc */
  u32 unk10; /* 0x10 */
  u32 unk14; /* 0x14 */
} BlockVec;

extern u32 FUN_000031f0();

/* Constructor: base setup, then clears the three trailing words. */
BlockVec * FUN_0019cae0(BlockVec *self)
{
  FUN_000031f0();
  self->unkc = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
