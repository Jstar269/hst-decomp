/* HSTMATCH module=EBOOT.BIN start=0x000be864 end=0x000be8a8 symbol=FUN_000be864 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000bed44(void *a, Arg1 b);
extern "C" void FUN_000beb14(void *a, int b, void *c);
extern "C" void FUN_000be864(void *a, void *b) { Arg1 x; x.v = 1; FUN_000bed44(a, x); FUN_000beb14(a, 1, b); }
