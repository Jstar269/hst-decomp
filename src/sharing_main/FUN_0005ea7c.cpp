/* HSTMATCH module=hstp_trans_main.prx start=0x0005ea7c end=0x0005eac0 symbol=FUN_0005ea7c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005f454(void *a, Arg1 b);
extern "C" void FUN_0005f224(void *a, int b, void *c);
extern "C" void FUN_0005ea7c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005f454(a, x); FUN_0005f224(a, 1, b); }
