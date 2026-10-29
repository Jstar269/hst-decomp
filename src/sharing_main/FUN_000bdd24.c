/* HSTMATCH module=hstp_trans_main.prx start=0x000bdd24 end=0x000bdd78 symbol=FUN_000bdd24 lang=c99 */
/* Clone of src/eboot/FUN_000ba9e0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/adhoc_net.h"

extern u8 DAT_0037b360;
extern u8 DAT_0037b370;

/* Fills in the default start-up configuration. */
void FUN_000bdd24(AdhocNet *self,AdhocConfig *config)
{
  if (config != 0) {
    config->bufSizeA = ADHOC_MAX_PAYLOAD;
    config->bufSizeB = ADHOC_MAX_PAYLOAD;
    config->unk08 = 1;
    config->unk0c = 0x10;
    config->poolSize = 0x20000;
    config->unk14 = 0x8000;
    config->product = &DAT_0037b360;
    config->groupName = &DAT_0037b370;
  }
}
