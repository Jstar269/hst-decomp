/* HSTMATCH module=hstp_trans_main.prx start=0x00152234 end=0x00152278 symbol=FUN_00152234 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00153efc(void *a, Arg1 b);
extern "C" void FUN_00153ccc(void *a, int b, void *c);
extern "C" void FUN_00152234(void *a, void *b) { Arg1 x; x.v = 1; FUN_00153efc(a, x); FUN_00153ccc(a, 1, b); }
