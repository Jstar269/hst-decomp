/* HSTMATCH module=hstp_trans_main.prx start=0x00152188 end=0x001521cc symbol=FUN_00152188 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00153be8(void *a, Arg1 b);
extern "C" void FUN_001539b8(void *a, int b, void *c);
extern "C" void FUN_00152188(void *a, void *b) { Arg1 x; x.v = 1; FUN_00153be8(a, x); FUN_001539b8(a, 1, b); }
