/* HSTMATCH module=EBOOT.BIN start=0x0013cf68 end=0x0013cfac symbol=FUN_0013cf68 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0013ef1c(void *a, Arg1 b);
extern "C" void FUN_0013ecb8(void *a, int b, void *c);
extern "C" void FUN_0013cf68(void *a, void *b) { Arg1 x; x.v = 1; FUN_0013ef1c(a, x); FUN_0013ecb8(a, 1, b); }
