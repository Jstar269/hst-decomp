/* HSTMATCH module=hstp_trans_main.prx start=0x00152e20 end=0x00152e64 symbol=FUN_00152e20 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00155cac(void *a, Arg1 b);
extern "C" void FUN_00155a18(void *a, int b, void *c);
extern "C" void FUN_00152e20(void *a, void *b) { Arg1 x; x.v = 1; FUN_00155cac(a, x); FUN_00155a18(a, 1, b); }
