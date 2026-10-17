/* HSTMATCH module=EBOOT.BIN start=0x000d9df8 end=0x000d9e3c symbol=FUN_000d9df8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000da648(void *a, Arg1 b);
extern "C" void FUN_000da3e4(void *a, int b, void *c);
extern "C" void FUN_000d9df8(void *a, void *b) { Arg1 x; x.v = 1; FUN_000da648(a, x); FUN_000da3e4(a, 1, b); }
