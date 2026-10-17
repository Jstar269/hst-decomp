/* HSTMATCH module=EBOOT.BIN start=0x0011605c end=0x001160a0 symbol=FUN_0011605c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00116a50(void *a, Arg1 b);
extern "C" void FUN_001167fc(void *a, int b, void *c);
extern "C" void FUN_0011605c(void *a, void *b) { Arg1 x; x.v = 1; FUN_00116a50(a, x); FUN_001167fc(a, 1, b); }
