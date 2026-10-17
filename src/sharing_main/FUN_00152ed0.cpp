/* HSTMATCH module=hstp_trans_main.prx start=0x00152ed0 end=0x00152f14 symbol=FUN_00152ed0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00155fc0(void *a, Arg1 b);
extern "C" void FUN_00155d90(void *a, int b, void *c);
extern "C" void FUN_00152ed0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00155fc0(a, x); FUN_00155d90(a, 1, b); }
