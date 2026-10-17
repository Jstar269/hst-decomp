/* HSTMATCH module=hstp_trans_main.prx start=0x0005505c end=0x000550a0 symbol=FUN_0005505c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000553e4(void *a, Arg1 b);
extern "C" void FUN_000551b4(void *a, int b, void *c);
extern "C" void FUN_0005505c(void *a, void *b) { Arg1 x; x.v = 1; FUN_000553e4(a, x); FUN_000551b4(a, 1, b); }
