/* HSTMATCH module=hstp_trans_main.prx start=0x0014817c end=0x001481c0 symbol=FUN_0014817c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001491d0(void *a, Arg1 b);
extern "C" void FUN_00148fa0(void *a, int b, void *c);
extern "C" void FUN_0014817c(void *a, void *b) { Arg1 x; x.v = 1; FUN_001491d0(a, x); FUN_00148fa0(a, 1, b); }
