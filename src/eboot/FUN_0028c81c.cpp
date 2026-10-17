/* HSTMATCH module=EBOOT.BIN start=0x0028c81c end=0x0028c860 symbol=FUN_0028c81c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0028d328(void *a, Arg1 b);
extern "C" void FUN_0028d084(void *a, int b, void *c);
extern "C" void FUN_0028c81c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0028d328(a, x); FUN_0028d084(a, 1, b); }
