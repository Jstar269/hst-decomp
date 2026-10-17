/* HSTMATCH module=hstp_trans_main.prx start=0x002469b0 end=0x002469f4 symbol=FUN_002469b0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00247960(void *a, Arg1 b);
extern "C" void FUN_0024762c(void *a, int b, void *c);
extern "C" void FUN_002469b0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00247960(a, x); FUN_0024762c(a, 1, b); }
