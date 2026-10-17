/* HSTMATCH module=EBOOT.BIN start=0x001a6550 end=0x001a6594 symbol=FUN_001a6550 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001a7c48(void *a, Arg1 b);
extern "C" void FUN_001a7a18(void *a, int b, void *c);
extern "C" void FUN_001a6550(void *a, void *b) { Arg1 x; x.v = 1; FUN_001a7c48(a, x); FUN_001a7a18(a, 1, b); }
