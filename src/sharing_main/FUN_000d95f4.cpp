/* HSTMATCH module=hstp_trans_main.prx start=0x000d95f4 end=0x000d9638 symbol=FUN_000d95f4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000da970(void *a, Arg1 b);
extern "C" void FUN_000da65c(void *a, int b, void *c);
extern "C" void FUN_000d95f4(void *a, void *b) { Arg1 x; x.v = 1; FUN_000da970(a, x); FUN_000da65c(a, 1, b); }
