/* HSTMATCH module=hstp_trans_main.prx start=0x001484f8 end=0x0014853c symbol=FUN_001484f8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0014a210(void *a, Arg1 b);
extern "C" void FUN_00149fbc(void *a, int b, void *c);
extern "C" void FUN_001484f8(void *a, void *b) { Arg1 x; x.v = 1; FUN_0014a210(a, x); FUN_00149fbc(a, 1, b); }
