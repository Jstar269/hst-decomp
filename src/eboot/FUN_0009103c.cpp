/* HSTMATCH module=EBOOT.BIN start=0x0009103c end=0x00091080 symbol=FUN_0009103c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0009156c(void *a, Arg1 b);
extern "C" void FUN_000912e8(void *a, int b, void *c);
extern "C" void FUN_0009103c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0009156c(a, x); FUN_000912e8(a, 1, b); }
