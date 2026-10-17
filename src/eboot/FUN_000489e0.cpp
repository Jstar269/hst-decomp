/* HSTMATCH module=EBOOT.BIN start=0x000489e0 end=0x00048a24 symbol=FUN_000489e0 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00048c78(void *a, Arg1 b);
extern "C" void FUN_00048a24(void *a, int b, void *c);
extern "C" void FUN_000489e0(void *a, void *b) { Arg1 x; x.v = 1; FUN_00048c78(a, x); FUN_00048a24(a, 1, b); }
