/* HSTMATCH module=hstp_trans_main.prx start=0x001480d0 end=0x00148114 symbol=FUN_001480d0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00148ebc(void *a, Arg1 b);
extern "C" void FUN_00148c8c(void *a, int b, void *c);
extern "C" void FUN_001480d0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00148ebc(a, x); FUN_00148c8c(a, 1, b); }
