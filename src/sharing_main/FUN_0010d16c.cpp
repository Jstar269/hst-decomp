/* HSTMATCH module=hstp_trans_main.prx start=0x0010d16c end=0x0010d1b0 symbol=FUN_0010d16c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0010e194(void *a, Arg1 b);
extern "C" void FUN_0010df64(void *a, int b, void *c);
extern "C" void FUN_0010d16c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0010e194(a, x); FUN_0010df64(a, 1, b); }
