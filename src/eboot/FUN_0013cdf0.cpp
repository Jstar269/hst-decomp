/* HSTMATCH module=EBOOT.BIN start=0x0013cdf0 end=0x0013ce34 symbol=FUN_0013cdf0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0013e88c(void *a, Arg1 b);
extern "C" void FUN_0013e638(void *a, int b, void *c);
extern "C" void FUN_0013cdf0(void *a, void *b) { Arg1 x; x.v = 1; FUN_0013e88c(a, x); FUN_0013e638(a, 1, b); }
