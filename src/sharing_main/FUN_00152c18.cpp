/* HSTMATCH module=hstp_trans_main.prx start=0x00152c18 end=0x00152c5c symbol=FUN_00152c18 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0015552c(void *a, Arg1 b);
extern "C" void FUN_00155278(void *a, int b, void *c);
extern "C" void FUN_00152c18(void *a, void *b) { Arg1 x; x.v = 1; FUN_0015552c(a, x); FUN_00155278(a, 1, b); }
