/* HSTMATCH module=EBOOT.BIN start=0x00234078 end=0x002340b4 symbol=FUN_00234078 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002f471c[90];
extern int DAT_002f4880;

int FUN_00234078(int i)
{
    if (i >= 0 && i < 90)
        return DAT_002f471c[i];
    return DAT_002f4880;
}
