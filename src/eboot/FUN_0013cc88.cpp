/* HSTMATCH module=EBOOT.BIN start=0x0013cc88 end=0x0013cccc symbol=FUN_0013cc88 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0013e1ac(void *a, Arg1 b);
extern "C" void FUN_0013df7c(void *a, int b, void *c);
extern "C" void FUN_0013cc88(void *a, void *b) { Arg1 x; x.v = 1; FUN_0013e1ac(a, x); FUN_0013df7c(a, 1, b); }
