/* HSTMATCH module=hstp_trans_main.prx start=0x00120f78 end=0x00120fbc symbol=FUN_00120f78 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0012196c(void *a, Arg1 b);
extern "C" void FUN_00121718(void *a, int b, void *c);
extern "C" void FUN_00120f78(void *a, void *b) { Arg1 x; x.v = 1; FUN_0012196c(a, x); FUN_00121718(a, 1, b); }
