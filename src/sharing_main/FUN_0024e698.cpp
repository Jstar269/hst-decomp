/* HSTMATCH module=hstp_trans_main.prx start=0x0024e698 end=0x0024e6dc symbol=FUN_0024e698 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0024ebb8(void *a, Arg1 b);
extern "C" void FUN_0024e818(void *a, int b, void *c);
extern "C" void FUN_0024e698(void *a, void *b) { Arg1 x; x.v = 1; FUN_0024ebb8(a, x); FUN_0024e818(a, 1, b); }
