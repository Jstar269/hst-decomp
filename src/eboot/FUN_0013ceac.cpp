/* HSTMATCH module=EBOOT.BIN start=0x0013ceac end=0x0013cef0 symbol=FUN_0013ceac */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0013ebc4(void *a, Arg1 b);
extern "C" void FUN_0013e970(void *a, int b, void *c);
extern "C" void FUN_0013ceac(void *a, void *b) { Arg1 x; x.v = 1; FUN_0013ebc4(a, x); FUN_0013e970(a, 1, b); }
