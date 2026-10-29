/* HSTMATCH module=hstp_trans_main.prx start=0x00297538 end=0x0029754c symbol=FUN_00297538 lang=c99 */
/* Clone of src/eboot/FUN_00285f28.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ClearedObj {
  u32 unk00;            /* 0x00 */
  u8 unk04;             /* 0x04 */
  char pad05[0xc5 - 0x5];
  u8 unkc5;             /* 0xc5 */
} ClearedObj;

ClearedObj * FUN_00297538(ClearedObj *self)
{
  self->unk00 = 0;
  self->unk04 = 0;
  self->unkc5 = 0;
  return self;
}
