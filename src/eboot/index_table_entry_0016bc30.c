/* HSTMATCH module=EBOOT.BIN start=0x0016bc30 end=0x0016bc70 symbol=FUN_0016bc30 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_003415a8;

void *FUN_0016bc30(int idx)
{
    char *base = DAT_003415a8 + 128;

    if (idx >= 0 && idx < 40) {
        return base + idx * 20 + 0x1058;
    }
    return 0;
}
