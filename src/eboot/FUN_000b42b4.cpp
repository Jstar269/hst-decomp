/* HSTMATCH module=EBOOT.BIN start=0x000b42b4 end=0x000b42f8 symbol=FUN_000b42b4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000b4c1c(void *a, Arg1 b);
extern "C" void FUN_000b49ec(void *a, int b, void *c);
extern "C" void FUN_000b42b4(void *a, void *b) { Arg1 x; x.v = 1; FUN_000b4c1c(a, x); FUN_000b49ec(a, 1, b); }
