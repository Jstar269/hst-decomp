/* HSTMATCH module=EBOOT.BIN start=0x00198228 end=0x00198278 symbol=FUN_00198228 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
extern void FUN_00198098(void *a, void *b, char *buf);
extern void FUN_00197834(void *a, char *buf, void *c, int d, int e, int f);

void FUN_00198228(void *a, void *b, void *c)
{
    char buf[1024];
    FUN_00198098(a, b, buf);
    FUN_00197834(a, buf, c, 1, 0, 0);
}
