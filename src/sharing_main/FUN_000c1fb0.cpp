/* HSTMATCH module=hstp_trans_main.prx start=0x000c1fb0 end=0x000c1ff4 symbol=FUN_000c1fb0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000c26f8(void *a, Arg1 b);
extern "C" void FUN_000c24c8(void *a, int b, void *c);
extern "C" void FUN_000c1fb0(void *a, void *b) { Arg1 x; x.v = 1; FUN_000c26f8(a, x); FUN_000c24c8(a, 1, b); }
