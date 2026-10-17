/* HSTMATCH module=hstp_trans_main.prx start=0x0006d250 end=0x0006d294 symbol=FUN_0006d250 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0006ec0c(void *a, Arg1 b);
extern "C" void FUN_0006e898(void *a, int b, void *c);
extern "C" void FUN_0006d250(void *a, void *b) { Arg1 x; x.v = 1; FUN_0006ec0c(a, x); FUN_0006e898(a, 1, b); }
