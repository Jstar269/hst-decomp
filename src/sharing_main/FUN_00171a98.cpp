/* HSTMATCH module=hstp_trans_main.prx start=0x00171a98 end=0x00171adc symbol=FUN_00171a98 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0017268c(void *a, Arg1 b);
extern "C" void FUN_00172408(void *a, int b, void *c);
extern "C" void FUN_00171a98(void *a, void *b) { Arg1 x; x.v = 1; FUN_0017268c(a, x); FUN_00172408(a, 1, b); }
