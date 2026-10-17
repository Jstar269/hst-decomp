/* HSTMATCH module=EBOOT.BIN start=0x002372ec end=0x00237330 symbol=FUN_002372ec */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00238524(void *a, Arg1 b);
extern "C" void FUN_00238280(void *a, int b, void *c);
extern "C" void FUN_002372ec(void *a, void *b) { Arg1 x; x.v = 1; FUN_00238524(a, x); FUN_00238280(a, 1, b); }
