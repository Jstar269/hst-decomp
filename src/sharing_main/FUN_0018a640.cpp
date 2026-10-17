/* HSTMATCH module=hstp_trans_main.prx start=0x0018a640 end=0x0018a684 symbol=FUN_0018a640 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0018aa18(void *a, Arg1 b);
extern "C" void FUN_0018a7e8(void *a, int b, void *c);
extern "C" void FUN_0018a640(void *a, void *b) { Arg1 x; x.v = 1; FUN_0018aa18(a, x); FUN_0018a7e8(a, 1, b); }
