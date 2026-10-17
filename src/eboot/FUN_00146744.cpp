/* HSTMATCH module=EBOOT.BIN start=0x00146744 end=0x00146788 symbol=FUN_00146744 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00147c94(void *a, Arg1 b);
extern "C" void FUN_00147a64(void *a, int b, void *c);
extern "C" void FUN_00146744(void *a, void *b) { Arg1 x; x.v = 1; FUN_00147c94(a, x); FUN_00147a64(a, 1, b); }
