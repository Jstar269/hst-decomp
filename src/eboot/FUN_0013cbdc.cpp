/* HSTMATCH module=EBOOT.BIN start=0x0013cbdc end=0x0013cc20 symbol=FUN_0013cbdc */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0013de98(void *a, Arg1 b);
extern "C" void FUN_0013dc68(void *a, int b, void *c);
extern "C" void FUN_0013cbdc(void *a, void *b) { Arg1 x; x.v = 1; FUN_0013de98(a, x); FUN_0013dc68(a, 1, b); }
