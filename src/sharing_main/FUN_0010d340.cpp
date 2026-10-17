/* HSTMATCH module=hstp_trans_main.prx start=0x0010d340 end=0x0010d384 symbol=FUN_0010d340 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0010e864(void *a, Arg1 b);
extern "C" void FUN_0010e5a0(void *a, int b, void *c);
extern "C" void FUN_0010d340(void *a, void *b) { Arg1 x; x.v = 1; FUN_0010e864(a, x); FUN_0010e5a0(a, 1, b); }
