/* HSTMATCH module=EBOOT.BIN start=0x00147274 end=0x001472b8 symbol=FUN_00147274 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001498ac(void *a, Arg1 b);
extern "C" void FUN_001495c8(void *a, int b, void *c);
extern "C" void FUN_00147274(void *a, void *b) { Arg1 x; x.v = 1; FUN_001498ac(a, x); FUN_001495c8(a, 1, b); }
