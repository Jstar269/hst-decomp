/* HSTMATCH module=EBOOT.BIN start=0x00147538 end=0x0014757c symbol=FUN_00147538 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0014a3c4(void *a, Arg1 b);
extern "C" void FUN_0014a130(void *a, int b, void *c);
extern "C" void FUN_00147538(void *a, void *b) { Arg1 x; x.v = 1; FUN_0014a3c4(a, x); FUN_0014a130(a, 1, b); }
