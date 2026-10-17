/* HSTMATCH module=hstp_trans_main.prx start=0x00224af4 end=0x00224b38 symbol=FUN_00224af4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00224ed4(void *a, Arg1 b);
extern "C" void FUN_00224ca0(void *a, int b, void *c);
extern "C" void FUN_00224af4(void *a, void *b) { Arg1 x; x.v = 1; FUN_00224ed4(a, x); FUN_00224ca0(a, 1, b); }
