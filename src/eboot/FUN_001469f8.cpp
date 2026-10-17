/* HSTMATCH module=EBOOT.BIN start=0x001469f8 end=0x00146a3c symbol=FUN_001469f8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00148a0c(void *a, Arg1 b);
extern "C" void FUN_001486f8(void *a, int b, void *c);
extern "C" void FUN_001469f8(void *a, void *b) { Arg1 x; x.v = 1; FUN_00148a0c(a, x); FUN_001486f8(a, 1, b); }
