/* HSTMATCH module=EBOOT.BIN start=0x00066098 end=0x000660dc symbol=FUN_00066098 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00066b60(void *a, Arg1 b);
extern "C" void FUN_00066930(void *a, int b, void *c);
extern "C" void FUN_00066098(void *a, void *b) { Arg1 x; x.v = 1; FUN_00066b60(a, x); FUN_00066930(a, 1, b); }
