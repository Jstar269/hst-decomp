/* HSTMATCH module=hstp_trans_main.prx start=0x0024696c end=0x002469b0 symbol=FUN_0024696c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00172314(void *a, Arg1 b);
extern "C" void FUN_001720e4(void *a, int b, void *c);
extern "C" void FUN_0024696c(void *a, void *b) { Arg1 x; x.v = 1; FUN_00172314(a, x); FUN_001720e4(a, 1, b); }
