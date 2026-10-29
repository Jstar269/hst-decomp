/* HSTMATCH module=EBOOT.BIN start=0x001c15c8 end=0x001c16b0 symbol=FUN_001c15c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed struct offsets and loop without unrolling; readability pass; exact match verified; names and types await human review. */
#include "hst/record_table.h"

extern char DAT_0034a678;
extern void FUN_001c1344(void);
extern void FUN_001da0a8(void);
extern void FUN_0022cd78(void);
extern void FUN_002340f4(void *);

/* Return the object to its initial state. */
void FUN_001c15c8(RecordTable *self)
{
    self->unk8438 = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2c = 0;
    self->unk30 = 1;
    self->unk34 = 2;
    self->unk38 = 0;
    self->unk3c = 0;
    self->unk40 = 0;
    self->unk43 = 0;
    self->unkb0 = 0;
    self->unkb1 = -1;
    self->unkb2 = -1;
    self->unkb3 = 0;
    self->unkb4 = 0;
    self->unkc4 = 0;
    self->unkc5 = 0;
    self->unkc6 = 0;
    self->unkc7 = 0;
    self->unk410 = 0;
    FUN_001c1344();

    /* walk the two byte pairs, two bytes per pass */
    int i = 0;
    RecordTable *cur = self;
    do {
        cur->pair[0][0] = 0;
        i++;
        cur->pair[0][1] = 0;
        cur = (RecordTable *)((char *)cur + 2);
    } while (i < 2);

    self->unkbc = 1;
    self->unkbd = 0;
    self->unkc0 = -1;
    self->unk8430 = 0;

    FUN_002340f4(&DAT_0034a678);
    FUN_001da0a8();
    FUN_0022cd78();
}
