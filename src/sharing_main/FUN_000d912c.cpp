/* HSTMATCH module=hstp_trans_main.prx start=0x000d912c end=0x000d9170 symbol=FUN_000d912c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000d9d84(void *a, Arg1 b);
extern "C" void FUN_000d9b54(void *a, int b, void *c);
extern "C" void FUN_000d912c(void *a, void *b) { Arg1 x; x.v = 1; FUN_000d9d84(a, x); FUN_000d9b54(a, 1, b); }
