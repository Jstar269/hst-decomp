/* HSTMATCH module=hstp_trans_main.prx start=0x0010d218 end=0x0010d25c symbol=FUN_0010d218 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0010e4ac(void *a, Arg1 b);
extern "C" void FUN_0010e278(void *a, int b, void *c);
extern "C" void FUN_0010d218(void *a, void *b) { Arg1 x; x.v = 1; FUN_0010e4ac(a, x); FUN_0010e278(a, 1, b); }
