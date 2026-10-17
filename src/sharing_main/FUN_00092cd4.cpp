/* HSTMATCH module=hstp_trans_main.prx start=0x00092cd4 end=0x00092d18 symbol=FUN_00092cd4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00093204(void *a, Arg1 b);
extern "C" void FUN_00092f80(void *a, int b, void *c);
extern "C" void FUN_00092cd4(void *a, void *b) { Arg1 x; x.v = 1; FUN_00093204(a, x); FUN_00092f80(a, 1, b); }
