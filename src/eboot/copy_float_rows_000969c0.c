/* HSTMATCH module=EBOOT.BIN start=0x000969c0 end=0x00096a90 symbol=FUN_000969c0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/player_record.h"

extern Float4 DAT_00338720;
extern Float4 DAT_00338730;
extern float DAT_00338740;
extern float DAT_00338744;
extern float DAT_00338748;
extern float DAT_0033874c;
extern int DAT_00338750;
extern short DAT_00338754;
extern signed char DAT_00338756;
extern signed char DAT_00338757;
extern int DAT_00338758;

/* Mirrors the row's record into the globals. */
void FUN_000969c0(SlotRow *row)
{
    DAT_00338720 = row->rec.a;
    DAT_00338730 = row->rec.b;
    DAT_00338740 = row->rec.c0;
    DAT_00338744 = row->rec.c1;
    DAT_00338748 = row->rec.c2;
    DAT_0033874c = row->rec.c3;
    DAT_00338750 = row->rec.d0;
    DAT_00338754 = row->rec.d1;
    DAT_00338756 = row->rec.d2;
    DAT_00338757 = row->rec.d3;
    DAT_00338758 = row->rec.d4;
}
