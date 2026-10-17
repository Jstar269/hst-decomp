/* HSTMATCH module=hstp_trans_main.prx start=0x000b75a4 end=0x000b75e8 symbol=FUN_000b75a4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000b7f0c(void *a, Arg1 b);
extern "C" void FUN_000b7cdc(void *a, int b, void *c);
extern "C" void FUN_000b75a4(void *a, void *b) { Arg1 x; x.v = 1; FUN_000b7f0c(a, x); FUN_000b7cdc(a, 1, b); }
