/* HSTMATCH module=EBOOT.BIN start=0x0006ea5c end=0x0006eaa0 symbol=FUN_0006ea5c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0006ed9c(void *a, Arg1 b);
extern "C" void FUN_0006eb6c(void *a, int b, void *c);
extern "C" void FUN_0006ea5c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0006ed9c(a, x); FUN_0006eb6c(a, 1, b); }
