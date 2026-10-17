/* HSTMATCH module=hstp_trans_main.prx start=0x001b3cc4 end=0x001b3d08 symbol=FUN_001b3cc4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001b5724(void *a, Arg1 b);
extern "C" void FUN_001b5410(void *a, int b, void *c);
extern "C" void FUN_001b3cc4(void *a, void *b) { Arg1 x; x.v = 1; FUN_001b5724(a, x); FUN_001b5410(a, 1, b); }
