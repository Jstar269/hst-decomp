/* HSTMATCH module=hstp_trans_main.prx start=0x000c2108 end=0x000c214c symbol=FUN_000c2108 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000c2d20(void *a, Arg1 b);
extern "C" void FUN_000c2af0(void *a, int b, void *c);
extern "C" void FUN_000c2108(void *a, void *b) { Arg1 x; x.v = 1; FUN_000c2d20(a, x); FUN_000c2af0(a, 1, b); }
