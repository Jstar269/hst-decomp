/* HSTMATCH module=hstp_trans_main.prx start=0x00186404 end=0x00186448 symbol=FUN_00186404 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0018704c(void *a, Arg1 b);
extern "C" void FUN_00186e1c(void *a, int b, void *c);
extern "C" void FUN_00186404(void *a, void *b) { Arg1 x; x.v = 1; FUN_0018704c(a, x); FUN_00186e1c(a, 1, b); }
