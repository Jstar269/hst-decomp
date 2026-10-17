/* HSTMATCH module=hstp_trans_main.prx start=0x0005bc3c end=0x0005bc80 symbol=FUN_0005bc3c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005bfa4(void *a, Arg1 b);
extern "C" void FUN_0005bd74(void *a, int b, void *c);
extern "C" void FUN_0005bc3c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005bfa4(a, x); FUN_0005bd74(a, 1, b); }
