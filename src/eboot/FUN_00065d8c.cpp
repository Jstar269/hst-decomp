/* HSTMATCH module=EBOOT.BIN start=0x00065d8c end=0x00065dd0 symbol=FUN_00065d8c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000667bc(void *a, Arg1 b);
extern "C" void FUN_000664a8(void *a, int b, void *c);
extern "C" void FUN_00065d8c(void *a, void *b) { Arg1 x; x.v = 1; FUN_000667bc(a, x); FUN_000664a8(a, 1, b); }
