/* HSTMATCH module=hstp_trans_main.prx start=0x000c1f04 end=0x000c1f48 symbol=FUN_000c1f04 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000c23e4(void *a, Arg1 b);
extern "C" void FUN_000c21b4(void *a, int b, void *c);
extern "C" void FUN_000c1f04(void *a, void *b) { Arg1 x; x.v = 1; FUN_000c23e4(a, x); FUN_000c21b4(a, 1, b); }
