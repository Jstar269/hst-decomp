/* HSTMATCH module=hstp_trans_main.prx start=0x000674ec end=0x00067530 symbol=FUN_000674ec */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00067fb4(void *a, Arg1 b);
extern "C" void FUN_00067d84(void *a, int b, void *c);
extern "C" void FUN_000674ec(void *a, void *b) { Arg1 x; x.v = 1; FUN_00067fb4(a, x); FUN_00067d84(a, 1, b); }
