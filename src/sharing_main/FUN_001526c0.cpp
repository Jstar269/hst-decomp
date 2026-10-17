/* HSTMATCH module=hstp_trans_main.prx start=0x001526c0 end=0x00152704 symbol=FUN_001526c0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00154dcc(void *a, Arg1 b);
extern "C" void FUN_00154b60(void *a, int b, void *c);
extern "C" void FUN_001526c0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00154dcc(a, x); FUN_00154b60(a, 1, b); }
