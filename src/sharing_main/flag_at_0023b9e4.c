/* HSTMATCH module=hstp_trans_main.prx start=0x0023b9e4 end=0x0023ba04 symbol=FUN_0023b9e4 lang=c99 */
/* Clone of src/eboot/flag_at_0022bf74.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern unsigned char *DAT_003ea8e8;

int FUN_0023b9e4(int a0)
{
    return *(unsigned char *)((char *)((a0 + 0x8c00) + (int)DAT_003ea8e8) + 0x3500) != 0;
}
