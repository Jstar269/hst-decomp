/* HSTMATCH module=EBOOT.BIN start=0x0028c760 end=0x0028c7a4 symbol=FUN_0028c760 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0028cfa0(void *a, Arg1 b);
extern "C" void FUN_0028cd6c(void *a, int b, void *c);
extern "C" void FUN_0028c760(void *a, void *b) { Arg1 x; x.v = 1; FUN_0028cfa0(a, x); FUN_0028cd6c(a, 1, b); }
