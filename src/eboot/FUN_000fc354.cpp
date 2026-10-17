/* HSTMATCH module=EBOOT.BIN start=0x000fc354 end=0x000fc398 symbol=FUN_000fc354 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000fc630(void *a, Arg1 b);
extern "C" void FUN_000fc400(void *a, int b, void *c);
extern "C" void FUN_000fc354(void *a, void *b) { Arg1 x; x.v = 1; FUN_000fc630(a, x); FUN_000fc400(a, 1, b); }
