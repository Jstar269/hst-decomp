/* HSTMATCH module=hstp_trans_main.prx start=0x00193b70 end=0x00193b8c symbol=FUN_00193b70 lang=c99 */
/* Clone of src/eboot/FUN_00187424.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Zeroes a five-word record and returns it. */
typedef struct ZeroRec5 {
  u32 unk0;  /* 0x00 */
  u32 unk4;  /* 0x04 */
  u32 unk8;  /* 0x08 */
  u32 unkc;  /* 0x0c */
  u32 unk10; /* 0x10 */
} ZeroRec5;

ZeroRec5 * FUN_00193b70(ZeroRec5 *rec)
{
  rec->unk0 = 0;
  rec->unk4 = 0;
  rec->unk8 = 0;
  rec->unkc = 0;
  rec->unk10 = 0;
  return rec;
}
