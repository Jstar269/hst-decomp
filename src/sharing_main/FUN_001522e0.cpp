/* HSTMATCH module=hstp_trans_main.prx start=0x001522e0 end=0x00152324 symbol=FUN_001522e0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001542f4(void *a, Arg1 b);
extern "C" void FUN_00153fe0(void *a, int b, void *c);
extern "C" void FUN_001522e0(void *a, void *b) { Arg1 x; x.v = 1; FUN_001542f4(a, x); FUN_00153fe0(a, 1, b); }
