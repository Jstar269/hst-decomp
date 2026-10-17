/* HSTMATCH module=hstp_trans_main.prx start=0x0007021c end=0x00070260 symbol=FUN_0007021c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0007055c(void *a, Arg1 b);
extern "C" void FUN_0007032c(void *a, int b, void *c);
extern "C" void FUN_0007021c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0007055c(a, x); FUN_0007032c(a, 1, b); }
