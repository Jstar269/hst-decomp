/* HSTMATCH module=EBOOT.BIN start=0x001650a8 end=0x001650ec symbol=FUN_001650a8 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00165d7c(void *a, Arg1 b);
extern "C" void FUN_00165a6c(void *a, int b, void *c);
extern "C" void FUN_001650a8(void *a, void *b) { Arg1 x; x.v = 1; FUN_00165d7c(a, x); FUN_00165a6c(a, 1, b); }
