/* HSTMATCH module=hstp_trans_main.prx start=0x0015b0d8 end=0x0015b11c symbol=FUN_0015b0d8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0015b948(void *a, Arg1 b);
extern "C" void FUN_0015b70c(void *a, int b, void *c);
extern "C" void FUN_0015b0d8(void *a, void *b) { Arg1 x; x.v = 1; FUN_0015b948(a, x); FUN_0015b70c(a, 1, b); }
