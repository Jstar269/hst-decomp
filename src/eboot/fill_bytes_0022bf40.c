/* HSTMATCH module=EBOOT.BIN start=0x0022bf40 end=0x0022bf74 symbol=FUN_0022bf40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off

extern unsigned char *DAT_003415a8;

void FUN_0022bf40(int v)
{
    int i;
    for (i = 0; i < 256; i++)
        ((unsigned char *)(i + (int)DAT_003415a8))[0xc100] = v;
}
