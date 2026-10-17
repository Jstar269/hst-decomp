/* HSTMATCH module=EBOOT.BIN start=0x000c16ac end=0x000c16f0 symbol=FUN_000c16ac */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000c1db0(void *a, Arg1 b);
extern "C" void FUN_000c1b1c(void *a, int b, void *c);
extern "C" void FUN_000c16ac(void *a, void *b) { Arg1 x; x.v = 1; FUN_000c1db0(a, x); FUN_000c1b1c(a, 1, b); }
