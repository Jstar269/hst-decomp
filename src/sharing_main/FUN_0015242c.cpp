/* HSTMATCH module=hstp_trans_main.prx start=0x0015242c end=0x00152470 symbol=FUN_0015242c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001546ec(void *a, Arg1 b);
extern "C" void FUN_001543d8(void *a, int b, void *c);
extern "C" void FUN_0015242c(void *a, void *b) { Arg1 x; x.v = 1; FUN_001546ec(a, x); FUN_001543d8(a, 1, b); }
