/* HSTMATCH module=hstp_trans_main.prx start=0x000c4d4c end=0x000c4d90 symbol=FUN_000c4d4c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000c5450(void *a, Arg1 b);
extern "C" void FUN_000c51bc(void *a, int b, void *c);
extern "C" void FUN_000c4d4c(void *a, void *b) { Arg1 x; x.v = 1; FUN_000c5450(a, x); FUN_000c51bc(a, 1, b); }
