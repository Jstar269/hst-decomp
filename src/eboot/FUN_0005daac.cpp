/* HSTMATCH module=EBOOT.BIN start=0x0005daac end=0x0005daf0 symbol=FUN_0005daac */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005e2c0(void *a, Arg1 b);
extern "C" void FUN_0005e05c(void *a, int b, void *c);
extern "C" void FUN_0005daac(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005e2c0(a, x); FUN_0005e05c(a, 1, b); }
