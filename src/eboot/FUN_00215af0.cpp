/* HSTMATCH module=EBOOT.BIN start=0x00215af0 end=0x00215b34 symbol=FUN_00215af0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00215ed0(void *a, Arg1 b);
extern "C" void FUN_00215c9c(void *a, int b, void *c);
extern "C" void FUN_00215af0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00215ed0(a, x); FUN_00215c9c(a, 1, b); }
