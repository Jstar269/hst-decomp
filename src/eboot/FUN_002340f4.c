/* HSTMATCH module=EBOOT.BIN start=0x002340f4 end=0x0023412c symbol=FUN_002340f4 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
void FUN_002340f4(int *p) { int i; *p = 89; for (i = 0; i < 10; i++) { p[1] = 89; p++; } }
