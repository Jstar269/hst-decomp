/* HSTMATCH module=EBOOT.BIN start=0x000be9bc end=0x000bea00 symbol=FUN_000be9bc */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000bf36c(void *a, Arg1 b);
extern "C" void FUN_000bf13c(void *a, int b, void *c);
extern "C" void FUN_000be9bc(void *a, void *b) { Arg1 x; x.v = 1; FUN_000bf36c(a, x); FUN_000bf13c(a, 1, b); }
