/* HSTMATCH module=EBOOT.BIN start=0x001f9390 end=0x001f93dc symbol=FUN_001f9390 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: used an early null return and reloaded the owner pointer for the final helper call; readability pass; exact match verified; names and types await human review. */
#include "hst/target_holder.h"

extern void FUN_00219a50(void *, int);

/* Copies the four mirrored floats into the target record and runs the record's follow-up helper. */
void FUN_001f9390(TargetHolder *self)
{
    TargetRec *target = self->rec;
    if (target == 0) return;
    target->unk10 = self->unk570;
    target->unk14 = self->unk574;
    target->unk18 = self->unk578;
    target->unk1c = self->unk57c;
    FUN_00219a50(self->rec, 3);
}
