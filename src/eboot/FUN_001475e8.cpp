/* HSTMATCH module=EBOOT.BIN start=0x001475e8 end=0x0014762c symbol=FUN_001475e8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0014a6d8(void *a, Arg1 b);
extern "C" void FUN_0014a4a8(void *a, int b, void *c);
extern "C" void FUN_001475e8(void *a, void *b) { Arg1 x; x.v = 1; FUN_0014a6d8(a, x); FUN_0014a4a8(a, 1, b); }
