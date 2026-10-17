/* HSTMATCH module=hstp_trans_main.prx start=0x00148228 end=0x0014826c symbol=FUN_00148228 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001494e4(void *a, Arg1 b);
extern "C" void FUN_001492b4(void *a, int b, void *c);
extern "C" void FUN_00148228(void *a, void *b) { Arg1 x; x.v = 1; FUN_001494e4(a, x); FUN_001492b4(a, 1, b); }
