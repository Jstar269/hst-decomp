/* HSTMATCH module=EBOOT.BIN start=0x0027df68 end=0x0027dfac symbol=FUN_0027df68 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0027e3dc(void *a, Arg1 b);
extern "C" void FUN_0027e0e8(void *a, int b, void *c);
extern "C" void FUN_0027df68(void *a, void *b) { Arg1 x; x.v = 1; FUN_0027e3dc(a, x); FUN_0027e0e8(a, 1, b); }
