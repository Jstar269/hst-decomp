/* HSTMATCH module=EBOOT.BIN start=0x000b4360 end=0x000b43a4 symbol=FUN_000b4360 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000b4f94(void *a, Arg1 b);
extern "C" void FUN_000b4d00(void *a, int b, void *c);
extern "C" void FUN_000b4360(void *a, void *b) { Arg1 x; x.v = 1; FUN_000b4f94(a, x); FUN_000b4d00(a, 1, b); }
