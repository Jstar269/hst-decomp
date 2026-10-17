/* HSTMATCH module=EBOOT.BIN start=0x00236808 end=0x0023684c symbol=FUN_00236808 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00166150(void *a, Arg1 b);
extern "C" void FUN_00165f20(void *a, int b, void *c);
extern "C" void FUN_00236808(void *a, void *b) { Arg1 x; x.v = 1; FUN_00166150(a, x); FUN_00165f20(a, 1, b); }
