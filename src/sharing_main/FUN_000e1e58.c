/* HSTMATCH module=hstp_trans_main.prx start=0x000e1e58 end=0x000e1e94 symbol=FUN_000e1e58 lang=c99 */
/* Clone of src/eboot/FUN_000ddc6c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/side_tally.h"

typedef struct DeltaObj {
  char pad00[0xc4];
  int delta_a;      /* 0xc4 */
  int delta_b;      /* 0xc8 */
} DeltaObj;

extern TallyOwner *DAT_003e19f0;

/* Adds the object's two delta words to the tally's first two counters. */
void FUN_000e1e58(DeltaObj *obj)
{
  DAT_003e19f0->tally->unk54 = DAT_003e19f0->tally->unk54 + obj->delta_a;
  DAT_003e19f0->tally->unk58 = DAT_003e19f0->tally->unk58 + obj->delta_b;
}
