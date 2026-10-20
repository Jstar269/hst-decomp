/* HSTMATCH module=EBOOT.BIN start=0x001c1f44 end=0x001c1f98 symbol=FUN_001c1f44 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern unsigned char DAT_00341ccc[];

unsigned char *FUN_001c1f44(int row, int col)
{
    if (row >= 0 && row < 2 && col >= 0 && col < 2)
        return DAT_00341ccc + 1046 + row * 0x4000 + col * 0x2000;
    return 0;
}
