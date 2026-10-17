/* HSTMATCH module=EBOOT.BIN start=0x000d5af0 end=0x000d5b34 symbol=FUN_000d5af0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000d70c4(void *a, Arg1 b);
extern "C" void FUN_000d6d74(void *a, int b, void *c);
extern "C" void FUN_000d5af0(void *a, void *b) { Arg1 x; x.v = 1; FUN_000d70c4(a, x); FUN_000d6d74(a, 1, b); }
