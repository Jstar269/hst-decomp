/* HSTMATCH module=EBOOT.BIN start=0x000be910 end=0x000be954 symbol=FUN_000be910 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000bf058(void *a, Arg1 b);
extern "C" void FUN_000bee28(void *a, int b, void *c);
extern "C" void FUN_000be910(void *a, void *b) { Arg1 x; x.v = 1; FUN_000bf058(a, x); FUN_000bee28(a, 1, b); }
