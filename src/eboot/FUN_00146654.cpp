/* HSTMATCH module=EBOOT.BIN start=0x00146654 end=0x00146698 symbol=FUN_00146654 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0005fa78(void *a, Arg1 b);
extern "C" void FUN_0005f848(void *a, int b, void *c);
extern "C" void FUN_00146654(void *a, void *b) { Arg1 x; x.v = 1; FUN_0005fa78(a, x); FUN_0005f848(a, 1, b); }
