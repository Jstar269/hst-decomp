/* HSTMATCH module=EBOOT.BIN start=0x000ba9e0 end=0x000baa34 symbol=FUN_000ba9e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/adhoc_net.h"

extern u8 DAT_002d4a98;
extern u8 DAT_002d4aa8;

/* Fills in the default start-up configuration. */
void FUN_000ba9e0(AdhocNet *self,AdhocConfig *config)
{
  if (config != 0) {
    config->bufSizeA = ADHOC_MAX_PAYLOAD;
    config->bufSizeB = ADHOC_MAX_PAYLOAD;
    config->unk08 = 1;
    config->unk0c = 0x10;
    config->poolSize = 0x20000;
    config->unk14 = 0x8000;
    config->product = &DAT_002d4a98;
    config->groupName = &DAT_002d4aa8;
  }
}
