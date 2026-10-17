/* HSTMATCH module=EBOOT.BIN start=0x00107458 end=0x0010749c symbol=FUN_00107458 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_001086ec(void *a, Arg1 b);
extern "C" void FUN_001084b8(void *a, int b, void *c);
extern "C" void FUN_00107458(void *a, void *b) { Arg1 x; x.v = 1; FUN_001086ec(a, x); FUN_001084b8(a, 1, b); }
