/* HSTMATCH module=hstp_trans_main.prx start=0x001e49a0 end=0x001e49b8 symbol=FUN_001e49a0 lang=c99 */
/* Clone of src/eboot/FUN_001d6bb0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Four-field record, zero-initialised. */
typedef struct Record { u32 unk00; u16 unk04; char pad06[2]; u32 unk08; u8 unk0c; } Record;

Record * FUN_001e49a0(Record *self)
{
  self->unk00 = 0;
  self->unk04 = 0;
  self->unk08 = 0;
  self->unk0c = 0;
  return self;
}
