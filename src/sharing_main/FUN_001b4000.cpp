/* HSTMATCH module=hstp_trans_main.prx start=0x001b4000 end=0x001b4044 symbol=FUN_001b4000 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001b5b34(void *a, Arg1 b);
extern "C" void FUN_001b5904(void *a, int b, void *c);
extern "C" void FUN_001b4000(void *a, void *b) { Arg1 x; x.v = 1; FUN_001b5b34(a, x); FUN_001b5904(a, 1, b); }
