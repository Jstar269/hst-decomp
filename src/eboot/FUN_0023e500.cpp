/* HSTMATCH module=EBOOT.BIN start=0x0023e500 end=0x0023e544 symbol=FUN_0023e500 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0023ea20(void *a, Arg1 b);
extern "C" void FUN_0023e680(void *a, int b, void *c);
extern "C" void FUN_0023e500(void *a, void *b) { Arg1 x; x.v = 1; FUN_0023ea20(a, x); FUN_0023e680(a, 1, b); }
