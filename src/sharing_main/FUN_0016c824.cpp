/* HSTMATCH module=hstp_trans_main.prx start=0x0016c824 end=0x0016c868 symbol=FUN_0016c824 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0016cb00(void *a, Arg1 b);
extern "C" void FUN_0016c8d0(void *a, int b, void *c);
extern "C" void FUN_0016c824(void *a, void *b) { Arg1 x; x.v = 1; FUN_0016cb00(a, x); FUN_0016c8d0(a, 1, b); }
