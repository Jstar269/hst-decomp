/* HSTMATCH module=hstp_trans_main.prx start=0x0005a440 end=0x0005a484 symbol=FUN_0005a440 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005acc0(void *a, Arg1 b);
extern "C" void FUN_0005a9ac(void *a, int b, void *c);
extern "C" void FUN_0005a440(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005acc0(a, x); FUN_0005a9ac(a, 1, b); }
