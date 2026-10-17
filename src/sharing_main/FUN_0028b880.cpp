/* HSTMATCH module=hstp_trans_main.prx start=0x0028b880 end=0x0028b8c4 symbol=FUN_0028b880 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0028c870(void *a, Arg1 b);
extern "C" void FUN_0028c640(void *a, int b, void *c);
extern "C" void FUN_0028b880(void *a, void *b) { Arg1 x; x.v = 1; FUN_0028c870(a, x); FUN_0028c640(a, 1, b); }
