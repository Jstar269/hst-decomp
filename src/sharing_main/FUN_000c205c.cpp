/* HSTMATCH module=hstp_trans_main.prx start=0x000c205c end=0x000c20a0 symbol=FUN_000c205c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000c2a0c(void *a, Arg1 b);
extern "C" void FUN_000c27dc(void *a, int b, void *c);
extern "C" void FUN_000c205c(void *a, void *b) { Arg1 x; x.v = 1; FUN_000c2a0c(a, x); FUN_000c27dc(a, 1, b); }
