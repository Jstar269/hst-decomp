/* HSTMATCH module=EBOOT.BIN start=0x0005dc60 end=0x0005dca4 symbol=FUN_0005dc60 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005e664(void *a, Arg1 b);
extern "C" void FUN_0005e434(void *a, int b, void *c);
extern "C" void FUN_0005dc60(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005e664(a, x); FUN_0005e434(a, 1, b); }
