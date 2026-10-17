/* HSTMATCH module=EBOOT.BIN start=0x00146b44 end=0x00146b88 symbol=FUN_00146b44 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00148e04(void *a, Arg1 b);
extern "C" void FUN_00148af0(void *a, int b, void *c);
extern "C" void FUN_00146b44(void *a, void *b) { Arg1 x; x.v = 1; FUN_00148e04(a, x); FUN_00148af0(a, 1, b); }
