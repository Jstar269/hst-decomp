/* HSTMATCH module=EBOOT.BIN start=0x001658a8 end=0x001658ec symbol=FUN_001658a8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001664c8(void *a, Arg1 b);
extern "C" void FUN_00166244(void *a, int b, void *c);
extern "C" void FUN_001658a8(void *a, void *b) { Arg1 x; x.v = 1; FUN_001664c8(a, x); FUN_00166244(a, 1, b); }
