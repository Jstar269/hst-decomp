/* HSTMATCH module=EBOOT.BIN start=0x001c1e20 end=0x001c1e60 symbol=FUN_001c1e20 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/unit_block.h"
#include "hst/screen_obj.h"

extern UnitOwner *DAT_003386c8;
extern ScreenEnv *DAT_00338ac4;

#define ALT_ENTRIES_OFFSET 0x3184 /* offset used instead of the entry array when the env flag is set */

/* Address of the active entry area inside the owner's block, or 0 without owner/env. */
int FUN_001c1e20(void)
{
    int result = 0;
    if (DAT_003386c8 != 0 && DAT_00338ac4 != 0) {
        int block = (int)DAT_003386c8->block;
        if (DAT_00338ac4->unk178 != 0) {
            result = block + ALT_ENTRIES_OFFSET;
        } else {
            result = block + 0x1bac;
        }
    }
    return result;
}
