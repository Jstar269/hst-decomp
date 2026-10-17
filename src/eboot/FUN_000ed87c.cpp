/* HSTMATCH module=EBOOT.BIN start=0x000ed87c end=0x000ed8c0 symbol=FUN_000ed87c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000edc6c(void *a, Arg1 b);
extern "C" void FUN_000ed9d8(void *a, int b, void *c);
extern "C" void FUN_000ed87c(void *a, void *b) { Arg1 x; x.v = 1; FUN_000edc6c(a, x); FUN_000ed9d8(a, 1, b); }
