/* HSTMATCH module=EBOOT.BIN start=0x002370b0 end=0x002370f4 symbol=FUN_002370b0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00237c38(void *a, Arg1 b);
extern "C" void FUN_002379a4(void *a, int b, void *c);
extern "C" void FUN_002370b0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00237c38(a, x); FUN_002379a4(a, 1, b); }
