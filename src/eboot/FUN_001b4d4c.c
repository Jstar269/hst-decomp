/* HSTMATCH module=EBOOT.BIN start=0x001b4d4c end=0x001b4dfc symbol=FUN_001b4d4c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

#define RAND_MULTIPLIER 0x343fd /* linear congruential generator constants */
#define RAND_INCREMENT 0x269ec3
#define RAND_OPTION_COUNT 5     /* option words per row */

/* Row of the option table: an id, the number of options in use and the option names. */
typedef struct OptionRow {
    int id;                          /* 0x00 */
    u8 count;                        /* 0x04 */
    char pad05[3];
    int option[RAND_OPTION_COUNT];   /* 0x08 */
} OptionRow;                         /* size 0x1c */

extern int DAT_0034178c;
extern OptionRow DAT_002e7700[];
extern int FUN_00062b64(void *, int, int);

/* For row `row_index` with id 0x15b and a slot in the second table (unk778[slot]): pick one of its options at random and load it into that slot. Returns -1 otherwise. */
int FUN_001b4d4c(SlotTable **ctx, int slot, int row_index)
{
    SlotTable *base = *ctx;
    OptionRow *row = &DAT_002e7700[row_index];
    int id = row->id;
    int seed = DAT_0034178c * RAND_MULTIPLIER + RAND_INCREMENT;
    int idx;
    int p;
    int r;

    DAT_0034178c = seed;
    idx = (int)(((unsigned int)seed >> 16) & 0x7fff) % (int)row->count;
    if (id == 0x15b && (p = base->unk778[slot]) != 0)
        r = FUN_00062b64((void *)p, row->option[idx], 0);
    else
        r = -1;
    return r;
}
