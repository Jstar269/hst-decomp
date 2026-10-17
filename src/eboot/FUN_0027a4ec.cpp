/* HSTMATCH module=EBOOT.BIN start=0x0027a4ec end=0x0027a530 symbol=FUN_0027a4ec */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0027b278(void *a, Arg1 b);
extern "C" void FUN_0027af84(void *a, int b, void *c);
extern "C" void FUN_0027a4ec(void *a, void *b) { Arg1 x; x.v = 1; FUN_0027b278(a, x); FUN_0027af84(a, 1, b); }
