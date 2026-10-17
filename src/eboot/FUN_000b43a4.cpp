/* HSTMATCH module=EBOOT.BIN start=0x000b43a4 end=0x000b43e8 symbol=FUN_000b43a4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000b539c(void *a, Arg1 b);
extern "C" void FUN_000b5088(void *a, int b, void *c);
extern "C" void FUN_000b43a4(void *a, void *b) { Arg1 x; x.v = 1; FUN_000b539c(a, x); FUN_000b5088(a, 1, b); }
