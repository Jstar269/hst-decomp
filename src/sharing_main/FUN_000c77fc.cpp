/* HSTMATCH module=hstp_trans_main.prx start=0x000c77fc end=0x000c7840 symbol=FUN_000c77fc */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000c7bd4(void *a, Arg1 b);
extern "C" void FUN_000c79a4(void *a, int b, void *c);
extern "C" void FUN_000c77fc(void *a, void *b) { Arg1 x; x.v = 1; FUN_000c7bd4(a, x); FUN_000c79a4(a, 1, b); }
