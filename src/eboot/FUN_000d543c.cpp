/* HSTMATCH module=EBOOT.BIN start=0x000d543c end=0x000d5480 symbol=FUN_000d543c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000d6094(void *a, Arg1 b);
extern "C" void FUN_000d5e64(void *a, int b, void *c);
extern "C" void FUN_000d543c(void *a, void *b) { Arg1 x; x.v = 1; FUN_000d6094(a, x); FUN_000d5e64(a, 1, b); }
