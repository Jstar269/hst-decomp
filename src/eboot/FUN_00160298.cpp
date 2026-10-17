/* HSTMATCH module=EBOOT.BIN start=0x00160298 end=0x001602dc symbol=FUN_00160298 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00160574(void *a, Arg1 b);
extern "C" void FUN_00160344(void *a, int b, void *c);
extern "C" void FUN_00160298(void *a, void *b) { Arg1 x; x.v = 1; FUN_00160574(a, x); FUN_00160344(a, 1, b); }
