/* HSTMATCH module=hstp_trans_main.prx start=0x00137e74 end=0x00137eb8 symbol=FUN_00137e74 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000ee39c(void *a, Arg1 b);
extern "C" void FUN_000ee148(void *a, int b, void *c);
extern "C" void FUN_00137e74(void *a, void *b) { Arg1 x; x.v = 1; FUN_000ee39c(a, x); FUN_000ee148(a, 1, b); }
