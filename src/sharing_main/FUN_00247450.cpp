/* HSTMATCH module=hstp_trans_main.prx start=0x00247450 end=0x00247494 symbol=FUN_00247450 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0024865c(void *a, Arg1 b);
extern "C" void FUN_002483b8(void *a, int b, void *c);
extern "C" void FUN_00247450(void *a, void *b) { Arg1 x; x.v = 1; FUN_0024865c(a, x); FUN_002483b8(a, 1, b); }
