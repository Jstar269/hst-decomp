/* HSTMATCH module=EBOOT.BIN start=0x0005afb4 end=0x0005aff8 symbol=FUN_0005afb4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005b31c(void *a, Arg1 b);
extern "C" void FUN_0005b0ec(void *a, int b, void *c);
extern "C" void FUN_0005afb4(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005b31c(a, x); FUN_0005b0ec(a, 1, b); }
