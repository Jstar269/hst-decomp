/* HSTMATCH module=hstp_trans_main.prx start=0x00148380 end=0x001483c4 symbol=FUN_00148380 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00149ba0(void *a, Arg1 b);
extern "C" void FUN_001498dc(void *a, int b, void *c);
extern "C" void FUN_00148380(void *a, void *b) { Arg1 x; x.v = 1; FUN_00149ba0(a, x); FUN_001498dc(a, 1, b); }
