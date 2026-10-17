/* HSTMATCH module=hstp_trans_main.prx start=0x001485b4 end=0x001485f8 symbol=FUN_001485b4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0014a568(void *a, Arg1 b);
extern "C" void FUN_0014a304(void *a, int b, void *c);
extern "C" void FUN_001485b4(void *a, void *b) { Arg1 x; x.v = 1; FUN_0014a568(a, x); FUN_0014a304(a, 1, b); }
