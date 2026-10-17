/* HSTMATCH module=EBOOT.BIN start=0x000d5904 end=0x000d5948 symbol=FUN_000d5904 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000d6c80(void *a, Arg1 b);
extern "C" void FUN_000d696c(void *a, int b, void *c);
extern "C" void FUN_000d5904(void *a, void *b) { Arg1 x; x.v = 1; FUN_000d6c80(a, x); FUN_000d696c(a, 1, b); }
