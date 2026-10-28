/* HSTMATCH module=EBOOT.BIN start=0x0008d388 end=0x0008d47c symbol=FUN_0008d388 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed 0xffff as unsigned short vs -1 signed short; readability pass; exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void *FUN_000114c0(void *p, int c, unsigned n);
extern void FUN_000d7e70(void *p);

/* Builds a Rec200 from six ids: default fill first, then the ids, then the base initialiser. */
Rec200 *FUN_0008d388(Rec200 *rec, s16 id0, s16 id1, s16 id2, s16 id3, s16 id4, s16 id5)
{
  FUN_000114c0(rec, 0, 0x9c);
  rec->unk22 = 0xffff;
  rec->unk20 = 0xffff;
  rec->ids[0] = REC_ID_NONE;
  rec->ids[1] = REC_ID_NONE;
  rec->ids[2] = REC_ID_NONE;
  rec->ids[3] = REC_ID_NONE;
  rec->ids[4] = REC_ID_NONE;
  rec->ids[5] = REC_ID_NONE;
  rec->unk7a = REC_ID_NONE;
  rec->str54[0] = '-';
  rec->str54[1] = '1';
  rec->str54[2] = 0;
  rec->str68[0] = '-';
  rec->str68[1] = '1';
  rec->str68[2] = 0;
  FUN_000114c0(rec, 0, sizeof(Rec200));
  rec->ids[0] = id0;
  rec->ids[1] = id1;
  rec->ids[2] = id2;
  rec->ids[3] = id3;
  rec->ids[4] = id4;
  rec->ids[5] = id5;
  FUN_000d7e70(rec);
  return rec;
}
