/* HSTMATCH module=EBOOT.BIN start=0x0014694c end=0x00146990 symbol=FUN_0014694c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00148614(void *a, Arg1 b);
extern "C" void FUN_001483e4(void *a, int b, void *c);
extern "C" void FUN_0014694c(void *a, void *b) { Arg1 x; x.v = 1; FUN_00148614(a, x); FUN_001483e4(a, 1, b); }
