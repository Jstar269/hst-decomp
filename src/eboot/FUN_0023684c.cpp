/* HSTMATCH module=EBOOT.BIN start=0x0023684c end=0x00236890 symbol=FUN_0023684c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00237828(void *a, Arg1 b);
extern "C" void FUN_002374f4(void *a, int b, void *c);
extern "C" void FUN_0023684c(void *a, void *b) { Arg1 x; x.v = 1; FUN_00237828(a, x); FUN_002374f4(a, 1, b); }
