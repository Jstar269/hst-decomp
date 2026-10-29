/* HSTMATCH module=EBOOT.BIN start=0x0019c384 end=0x0019c3b8 symbol=FUN_0019c384 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_00190724(void *);
extern void FUN_002345f8(char *);
extern void *DAT_003415d4; /* save menu */
extern char DAT_0034a678;

/* Notify when the save menu's check (FUN_00190724) is non-zero. */
void FUN_0019c384(void)
{
    if (FUN_00190724(DAT_003415d4) != 0)
        FUN_002345f8(&DAT_0034a678);
}
