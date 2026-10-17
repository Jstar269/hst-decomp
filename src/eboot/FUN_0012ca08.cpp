/* HSTMATCH module=EBOOT.BIN start=0x0012ca08 end=0x0012ca4c symbol=FUN_0012ca08 */
/* Clone of src/eboot/FUN_0028c760.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
struct Arg1 { int v; };
extern "C" void FUN_000e92c8(void *a, Arg1 b);
extern "C" void FUN_000e9074(void *a, int b, void *c);
extern "C" void FUN_0012ca08(void *a, void *b) { Arg1 x; x.v = 1; FUN_000e92c8(a, x); FUN_000e9074(a, 1, b); }
