/* HSTMATCH module=EBOOT.BIN start=0x00054510 end=0x00054554 symbol=FUN_00054510 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_00054898(void *a, Arg1 b);
extern "C" void FUN_00054668(void *a, int b, void *c);
extern "C" void FUN_00054510(void *a, void *b) { Arg1 x; x.v = 1; FUN_00054898(a, x); FUN_00054668(a, 1, b); }
