/* HSTMATCH module=hstp_trans_main.prx start=0x0023b9b0 end=0x0023b9e4 symbol=FUN_0023b9b0 lang=c99 */
/* Clone of src/eboot/fill_bytes_0022bf40.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off

extern unsigned char *DAT_003ea8e8;

void FUN_0023b9b0(int v)
{
    int i;
    for (i = 0; i < 256; i++)
        ((unsigned char *)(i + (int)DAT_003ea8e8))[0xc100] = v;
}
