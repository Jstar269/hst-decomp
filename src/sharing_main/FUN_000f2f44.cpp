/* HSTMATCH module=hstp_trans_main.prx start=0x000f2f44 end=0x000f2f88 symbol=FUN_000f2f44 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000f3334(void *a, Arg1 b);
extern "C" void FUN_000f30a0(void *a, int b, void *c);
extern "C" void FUN_000f2f44(void *a, void *b) { Arg1 x; x.v = 1; FUN_000f3334(a, x); FUN_000f30a0(a, 1, b); }
