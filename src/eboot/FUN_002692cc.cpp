/* HSTMATCH module=EBOOT.BIN start=0x002692cc end=0x00269310 symbol=FUN_002692cc */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_002695a8(void *a, Arg1 b);
extern "C" void FUN_00269378(void *a, int b, void *c);
extern "C" void FUN_002692cc(void *a, void *b) { Arg1 x; x.v = 1; FUN_002695a8(a, x); FUN_00269378(a, 1, b); }
