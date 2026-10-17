/* HSTMATCH module=EBOOT.BIN start=0x0028c6a4 end=0x0028c6e8 symbol=FUN_0028c6a4 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0028cc88(void *a, Arg1 b);
extern "C" void FUN_0028c9f4(void *a, int b, void *c);
extern "C" void FUN_0028c6a4(void *a, void *b) { Arg1 x; x.v = 1; FUN_0028cc88(a, x); FUN_0028c9f4(a, 1, b); }
