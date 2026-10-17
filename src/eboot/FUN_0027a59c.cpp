/* HSTMATCH module=EBOOT.BIN start=0x0027a59c end=0x0027a5e0 symbol=FUN_0027a59c */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0027b58c(void *a, Arg1 b);
extern "C" void FUN_0027b35c(void *a, int b, void *c);
extern "C" void FUN_0027a59c(void *a, void *b) { Arg1 x; x.v = 1; FUN_0027b58c(a, x); FUN_0027b35c(a, 1, b); }
