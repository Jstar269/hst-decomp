/* HSTMATCH module=EBOOT.BIN start=0x002b39e0 end=0x002b3a24 symbol=FUN_002b39e0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_002b4ac8(void *a, Arg1 b);
extern "C" void FUN_002b46a0(void *a, int b, void *c);
extern "C" void FUN_002b39e0(void *a, void *b) { Arg1 x; x.v = 1; FUN_002b4ac8(a, x); FUN_002b46a0(a, 1, b); }
