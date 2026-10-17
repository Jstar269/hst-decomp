/* HSTMATCH module=EBOOT.BIN start=0x0013c8c4 end=0x0013c908 symbol=FUN_0013c8c4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0013d248(void *a, Arg1 b);
extern "C" void FUN_0013d018(void *a, int b, void *c);
extern "C" void FUN_0013c8c4(void *a, void *b) { Arg1 x; x.v = 1; FUN_0013d248(a, x); FUN_0013d018(a, 1, b); }
