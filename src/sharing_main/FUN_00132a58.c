/* HSTMATCH module=hstp_trans_main.prx start=0x00132a58 end=0x00132ae0 symbol=FUN_00132a58 lang=c99 */
/* Clone of src/eboot/FUN_001277e8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/motion_obj.h"

extern u32 DAT_003e47e8;  /* entry table, MOTION_TABLE_COUNT entries */
extern void FUN_00058090();
extern void FUN_00094eb8();

/* Hand every non-empty table entry to the helper together with the item link at +0x58. */
void FUN_00132a58(int self)
{
  MotionEntry *entry;
  int link;
  int i;
  int offset;

  FUN_00094eb8();
  link = *(int *)(self + 0x58);
  if (link != 0) {
    i = 0;
    offset = 0;
    do {
      entry = (MotionEntry *)(DAT_003e47e8 + offset);
      if ((entry != (MotionEntry *)0x0) && (entry->unk00 != 0)) {
        FUN_00058090(link,i,entry,0);
      }
      i = i + 1;
      offset = offset + sizeof(MotionEntry);
    } while (i < MOTION_TABLE_COUNT);
  }
}
