/* HSTMATCH module=hstp_trans_main.prx start=0x00055108 end=0x0005514c symbol=FUN_00055108 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000556f8(void *a, Arg1 b);
extern "C" void FUN_000554c8(void *a, int b, void *c);
extern "C" void FUN_00055108(void *a, void *b) { Arg1 x; x.v = 1; FUN_000556f8(a, x); FUN_000554c8(a, 1, b); }
