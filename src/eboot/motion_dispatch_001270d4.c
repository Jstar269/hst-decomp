/* HSTMATCH module=EBOOT.BIN start=0x001270d4 end=0x001271dc symbol=FUN_001270d4 lang=c99 helpers=FUN_00126d1c@0x00126d1c-0x00126d48 */
/* Hand-written reconstruction from the disassembly (same-file static log stub FUN_00126d1c placed by helpers=; the first range forwards param_2 with -1/0); exact match verified; names and types await human review. */
extern char DAT_002da818[];
static void FUN_00126d1c(...) {}
extern void FUN_0012a254(int, ...);

void FUN_001270d4(int param_1, int param_2)
{
    if (param_2 < 0)
        FUN_00126d1c(DAT_002da818);
    if (param_2 < 6)
        FUN_0012a254(param_1, param_2, -1, 0);
    else if (param_2 < 0xe)
        FUN_0012a254(param_1, 6, param_2 - 6, 0);
    else if (param_2 < 0x14)
        FUN_0012a254(param_1, 7, param_2 - 0xe, 0);
    else if (param_2 < 0x1c)
        FUN_0012a254(param_1, 8, param_2 - 0x14, 0);
    else if (param_2 < 0x26)
        FUN_0012a254(param_1, 9, param_2 - 0x1c, 0);
    else if (param_2 < 0x29)
        FUN_0012a254(param_1, 10, param_2 - 0x26, 0);
    else
        FUN_00126d1c(DAT_002da818);
}
