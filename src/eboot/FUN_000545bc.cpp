/* HSTMATCH module=EBOOT.BIN start=0x000545bc end=0x00054600 symbol=FUN_000545bc */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00054bac(void *a, Arg1 b);
extern "C" void FUN_0005497c(void *a, int b, void *c);
extern "C" void FUN_000545bc(void *a, void *b) { Arg1 x; x.v = 1; FUN_00054bac(a, x); FUN_0005497c(a, 1, b); }
