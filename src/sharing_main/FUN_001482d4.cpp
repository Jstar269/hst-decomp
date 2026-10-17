/* HSTMATCH module=hstp_trans_main.prx start=0x001482d4 end=0x00148318 symbol=FUN_001482d4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001497f8(void *a, Arg1 b);
extern "C" void FUN_001495c8(void *a, int b, void *c);
extern "C" void FUN_001482d4(void *a, void *b) { Arg1 x; x.v = 1; FUN_001497f8(a, x); FUN_001495c8(a, 1, b); }
