/* HSTMATCH module=EBOOT.BIN start=0x000bea68 end=0x000beaac symbol=FUN_000bea68 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000bf680(void *a, Arg1 b);
extern "C" void FUN_000bf450(void *a, int b, void *c);
extern "C" void FUN_000bea68(void *a, void *b) { Arg1 x; x.v = 1; FUN_000bf680(a, x); FUN_000bf450(a, 1, b); }
