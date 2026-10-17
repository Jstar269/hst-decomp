/* HSTMATCH module=hstp_trans_main.prx start=0x0005e8c8 end=0x0005e90c symbol=FUN_0005e8c8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005f0b0(void *a, Arg1 b);
extern "C" void FUN_0005ee4c(void *a, int b, void *c);
extern "C" void FUN_0005e8c8(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005f0b0(a, x); FUN_0005ee4c(a, 1, b); }
