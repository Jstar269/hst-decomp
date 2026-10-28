/* HSTMATCH module=hstp_trans_main.prx start=0x00244178 end=0x002441b4 symbol=FUN_00244178 lang=c99 */
/* Clone of src/eboot/table_lookup90_00234078.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0039cfe0[90];
extern int DAT_0039d144;

int FUN_00244178(int i)
{
    if (i >= 0 && i < 90)
        return DAT_0039cfe0[i];
    return DAT_0039d144;
}
