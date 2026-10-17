/* HSTMATCH module=hstp_trans_main.prx start=0x00152b5c end=0x00152ba0 symbol=FUN_00152b5c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00155194(void *a, Arg1 b);
extern "C" void FUN_00154eb0(void *a, int b, void *c);
extern "C" void FUN_00152b5c(void *a, void *b) { Arg1 x; x.v = 1; FUN_00155194(a, x); FUN_00154eb0(a, 1, b); }
