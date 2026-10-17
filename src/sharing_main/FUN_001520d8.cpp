/* HSTMATCH module=hstp_trans_main.prx start=0x001520d8 end=0x0015211c symbol=FUN_001520d8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001538d4(void *a, Arg1 b);
extern "C" void FUN_00153670(void *a, int b, void *c);
extern "C" void FUN_001520d8(void *a, void *b) { Arg1 x; x.v = 1; FUN_001538d4(a, x); FUN_00153670(a, 1, b); }
