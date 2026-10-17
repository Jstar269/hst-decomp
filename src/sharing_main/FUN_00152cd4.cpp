/* HSTMATCH module=hstp_trans_main.prx start=0x00152cd4 end=0x00152d18 symbol=FUN_00152cd4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00155924(void *a, Arg1 b);
extern "C" void FUN_00155610(void *a, int b, void *c);
extern "C" void FUN_00152cd4(void *a, void *b) { Arg1 x; x.v = 1; FUN_00155924(a, x); FUN_00155610(a, 1, b); }
