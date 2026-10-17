/* HSTMATCH module=hstp_trans_main.prx start=0x001c8cf4 end=0x001c8d38 symbol=FUN_001c8cf4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001c90cc(void *a, Arg1 b);
extern "C" void FUN_001c8e9c(void *a, int b, void *c);
extern "C" void FUN_001c8cf4(void *a, void *b) { Arg1 x; x.v = 1; FUN_001c90cc(a, x); FUN_001c8e9c(a, 1, b); }
