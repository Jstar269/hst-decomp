/* HSTMATCH module=EBOOT.BIN start=0x001ce554 end=0x001ce598 symbol=FUN_001ce554 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001cf494(void *a, Arg1 b);
extern "C" void FUN_001cf264(void *a, int b, void *c);
extern "C" void FUN_001ce554(void *a, void *b) { Arg1 x; x.v = 1; FUN_001cf494(a, x); FUN_001cf264(a, 1, b); }
