/* HSTMATCH module=EBOOT.BIN start=0x0008d650 end=0x0008d6cc symbol=FUN_0008d650 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void FUN_000114c0(void *, int, int);

/* Clears a Rec200-sized record (0x9c bytes) and sets the default ids and "-1" strings. */
Rec200 *FUN_0008d650(Rec200 *rec)
{
  s16 *ids = rec->ids;
  FUN_000114c0(rec, 0, 0x9c);
  rec->unk22 = 0xffff;
  rec->unk20 = 0xffff;
  ids[0] = REC_ID_NONE;
  ids[1] = REC_ID_NONE;
  ids[2] = REC_ID_NONE;
  ids[3] = REC_ID_NONE;
  ids[4] = REC_ID_NONE;
  ids[5] = REC_ID_NONE;
  rec->unk7a = REC_ID_NONE;
  rec->str54[0] = '-';
  rec->str54[1] = '1';
  rec->str54[2] = 0;
  rec->str68[0] = '-';
  rec->str68[1] = '1';
  rec->str68[2] = 0;
  return rec;
}
