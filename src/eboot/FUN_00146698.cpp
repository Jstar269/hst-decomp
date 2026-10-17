/* HSTMATCH module=EBOOT.BIN start=0x00146698 end=0x001466dc symbol=FUN_00146698 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00147980(void *a, Arg1 b);
extern "C" void FUN_00147750(void *a, int b, void *c);
extern "C" void FUN_00146698(void *a, void *b) { Arg1 x; x.v = 1; FUN_00147980(a, x); FUN_00147750(a, 1, b); }
