/* HSTMATCH module=EBOOT.BIN start=0x001c1d74 end=0x001c1e20 symbol=FUN_001c1d74 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001c1d74.c (tag: a1) */
#include "hst/unit_block.h"
#include "hst/screen_obj.h"
#include "hst/slot_block.h"

extern UnitOwner *DAT_003386c8;
extern ScreenEnv *DAT_00338ac4;
extern SetupData *DAT_003415a8;
extern int FUN_000bbba4(void *, void *);

/* The setup data's string field, or 0 when there is no setup data. */
static inline char *GetField20(void)
{
    char *r = 0;
    SetupData *g = DAT_003415a8;
    if (g != 0) {
        r = g->unk20;
    }
    return r;
}

/* Find the entry whose key matches the env's lookup key (the string field when the env flag is set). */
void *FUN_001c1d74(void)
{
    int i;
    void *result;
    UnitBlock *cur;
    int key;

    result = 0;
    if (DAT_003386c8 != 0 && DAT_00338ac4 != 0) {
        cur = DAT_003386c8->block; /* advanced one entry per pass */
        if (DAT_00338ac4->unk178 != 0) {
            result = GetField20();
        } else {
            i = 0;
            do {
                key = FUN_000bbba4(DAT_00338ac4, (char *)DAT_00338ac4 + 0x3e);
                if (cur->entry[0].key == key) {
                    result = &cur->entry[0];
                }
                i = i + 1;
                cur = (UnitBlock *)((char *)cur + sizeof(UnitEntry));
            } while (i < UNIT_ENTRY_COUNT);
        }
    }
    return result;
}
