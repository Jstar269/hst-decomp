/* HSTMATCH module=hstp_trans_main.prx start=0x00120e40 end=0x00120e84 symbol=FUN_00120e40 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001215a4(void *a, Arg1 b);
extern "C" void FUN_00121340(void *a, int b, void *c);
extern "C" void FUN_00120e40(void *a, void *b) { Arg1 x; x.v = 1; FUN_001215a4(a, x); FUN_00121340(a, 1, b); }
