/* HSTMATCH module=EBOOT.BIN start=0x0013c9d8 end=0x0013ca1c symbol=FUN_0013c9d8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0013d55c(void *a, Arg1 b);
extern "C" void FUN_0013d32c(void *a, int b, void *c);
extern "C" void FUN_0013c9d8(void *a, void *b) { Arg1 x; x.v = 1; FUN_0013d55c(a, x); FUN_0013d32c(a, 1, b); }
