/* HSTMATCH module=EBOOT.BIN start=0x0006bc68 end=0x0006bcac symbol=FUN_0006bc68 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_0006d624(void *a, Arg1 b);
extern "C" void FUN_0006d2b0(void *a, int b, void *c);
extern "C" void FUN_0006bc68(void *a, void *b) { Arg1 x; x.v = 1; FUN_0006d624(a, x); FUN_0006d2b0(a, 1, b); }
