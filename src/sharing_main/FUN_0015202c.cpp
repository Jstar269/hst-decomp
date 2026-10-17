/* HSTMATCH module=hstp_trans_main.prx start=0x0015202c end=0x00152070 symbol=FUN_0015202c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0015357c(void *a, Arg1 b);
extern "C" void FUN_0015334c(void *a, int b, void *c);
extern "C" void FUN_0015202c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0015357c(a, x); FUN_0015334c(a, 1, b); }
